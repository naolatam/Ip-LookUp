#include "MainForm.h"



std::string SystemStringToStdString(System::String^ managedString) {

    // Conversion de System::String^ en const wchar_t*
    const wchar_t* nativeString = (const wchar_t*)(IpLookUp::Runtime::InteropServices::Marshal::StringToHGlobalUni(managedString)).ToPointer();

    // Conversion de const wchar_t* en std::wstring
    std::wstring wideString(nativeString);
 
    // Libération de la mémoire allouée par Marshal::StringToHGlobalUni
    IpLookUp::Runtime::InteropServices::Marshal::FreeHGlobal(IpLookUp::IntPtr((void*)nativeString));

    // Conversion de std::wstring en std::string
    std::string stdString(wideString.begin(), wideString.end());
    return stdString;

}

System::String^ StdStringToSystemString(std::string nativeString) {
    array<wchar_t>^ wideCharArray = gcnew array<wchar_t>(nativeString.length() + 1);

    for (size_t i = 0; i < nativeString.length(); ++i) {
        wideCharArray[i] = static_cast<wchar_t>(nativeString[i]);
    }
    wideCharArray[nativeString.length()] = L'\0';

    String^ managedString = gcnew String(wideCharArray);
    return managedString;
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

bool isIPv4(std::string& str) {
    std::regex pattern("^\\b(?:\\d{1,3}\\.){3}\\d{1,3}\\b$");
    return std::regex_match(str, pattern);
}

bool isIPv6(std::string& str) {
    std::regex pattern("^\\b(?:[0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}\\b$");
    return std::regex_match(str, pattern);
}

bool isIp(std::string str) {

    bool res = false;
    if (isIPv4(str)) {
        res = true;
    }
    if (isIPv6(str)) {
        res = true;
    }
    return res;
}

System::Void IpLookUp::MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

  std::string ip = SystemStringToStdString(MainForm::textBox1->Text);
  for (int i = 0; i < IpLookUp::MainForm::panel4->Controls->Count; i++) {
      Control^ childControl = IpLookUp::MainForm::panel4->Controls[i];
      childControl->Text = ""; 
  }
  if (isIp(ip)) {


      IpLookUp::CurlWrapper^ curlWrapper = gcnew IpLookUp::CurlWrapper();
      void* curlHandle = curlWrapper->GetCurlHandle();
      std::string urlP = "https://ipinfo.io/" + ip + "?token=ce5fa2590e7da3";
      const char* url = urlP.c_str();
      // Configuration de la requête GET
      curl_easy_setopt(curlHandle, CURLOPT_URL, url);
      curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, 1L);

      // Configuration de la fonction de rappel pour stocker la réponse
      std::string response;
      curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);

      // Effectuer la requête GET
      CURLcode res = curl_easy_perform(curlHandle);

      // Vérifier si la requête a réussi
      if (res == CURLE_OK) {

          json js = json::parse(response);
          String^ as = StdStringToSystemString(js["org"].get<std::string>());
          array<Char>^ delimiterChars = { ' ' };
          array<String^>^ ASN = as->Split(delimiterChars);

          for (int i = 2; i < ASN->Length; i++) {
              ASN[1] += " " + ASN[i];
          }
          IpLookUp::MainForm::statusL->Text = "Success";
          IpLookUp::MainForm::countryL->Text = StdStringToSystemString(js["country"].get<std::string>());
          IpLookUp::MainForm::stateL->Text = StdStringToSystemString(js["region"].get<std::string>());
          IpLookUp::MainForm::cityL->Text = StdStringToSystemString(js["city"].get<std::string>());
          IpLookUp::MainForm::zip_codeL->Text = StdStringToSystemString(js["postal"].get<std::string>());
          IpLookUp::MainForm::LocationL->Text = StdStringToSystemString(js["loc"].get<std::string>());
          IpLookUp::MainForm::timeZoneL->Text = StdStringToSystemString(js["timezone"].get<std::string>());
          IpLookUp::MainForm::asnL->Text = ASN[0];
          IpLookUp::MainForm::asnNameL->Text = ASN[1];
          IpLookUp::MainForm::ipL->Text = StdStringToSystemString(ip);







      } else {
          IpLookUp::MainForm::statusL->Text = "Failed";
          IpLookUp::MainForm::countryL->Text = "HTTP_Req_ERR";

      }
  }
  else {
      IpLookUp::MainForm::statusL->Text = "Failed";
      IpLookUp::MainForm::countryL->Text = "INVALID_IP";

  }


}