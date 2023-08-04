
#include <curl/curl.h>

using namespace System;

namespace IpLookUp {
    public ref class CurlWrapper {
    public:
        CurlWrapper() {
            curl_ = curl_easy_init();
        }

        ~CurlWrapper() {
            if (curl_) {
                curl_easy_cleanup(curl_);
            }
        }

        void* GetCurlHandle() {
            return curl_;
        }

    private:
        CURL* curl_;
    };
}