#include "main.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::NetworkInformation;

int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
   
    Application::SetCompatibleTextRenderingDefault(false);

    IpLookUp::MainForm form; 
    IpLookUp::MainFormNoInternet formWithOutInternet;
    if (!isInternet()) {
        Application::Run(% formWithOutInternet);
    }
    else {
        Application::Run(% form);

    }


    return 0;
}

bool isInternet()
{
    bool isInternetAvailable = false;

    array<NetworkInterface^>^ interfaces = NetworkInterface::GetAllNetworkInterfaces();
    for each (NetworkInterface ^ netInterface in interfaces) {
        if (netInterface->GetIsNetworkAvailable()) {
            isInternetAvailable = true;
            break;
        }
    }

    return isInternetAvailable;

}