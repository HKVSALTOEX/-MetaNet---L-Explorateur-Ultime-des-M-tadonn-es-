#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

std::string obtenirGeolocalisation(const std::string& ip) {
    std::string url = "http://ipinfo.io/" + ip + "/json";
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](void* contents, size_t size, size_t nmemb, void* userp) {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    if (res != CURLE_OK) {
        return "Erreur: " + std::string(curl_easy_strerror(res));
    }

    Json::CharReaderBuilder rbuilder;
    std::string errs;
    Json::Value jsonObj;
    std::istringstream sstr(readBuffer);
    std::string doc = sstr.str();

    if (Json::parseFromStream(rbuilder, sstr, &jsonObj, &errs)) {
        return "Continent: " + jsonObj["continent"].asString() + "\n"
               "Pays: " + jsonObj["country"].asString() + "\n"
               "Région: " + jsonObj["region"].asString() + "\n"
               "Ville: " + jsonObj["city"].asString() + "\n"
               "Zone précise: " + jsonObj["loc"].asString();
    }

    return "Erreur dans la réponse JSON";
}

int main() {
    std::string ip = "votre_adresse_ip_publique"; // Remplacez par l'adresse IP publique obtenue
    std::cout << obtenirGeolocalisation(ip) << std::endl;
    return 0;
}
