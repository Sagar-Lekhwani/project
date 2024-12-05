#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

// Callback function for writing data received from libcurl to a file
size_t WriteCallback(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to download an image from a URL
bool downloadImage(const std::string& url, const std::string& outputFilename) {
    CURL* curl;
    CURLcode res;
    FILE* fp;

    curl = curl_easy_init(); // Initialize libcurl
    if (curl) {
        fp = fopen(outputFilename.c_str(), "wb"); // Open file for writing
        if (!fp) {
            std::cerr << "Failed to open file: " << outputFilename << "\n";
            return false;
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl); // Perform the request
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << "\n";
        }

        fclose(fp);
        curl_easy_cleanup(curl);
        return (res == CURLE_OK);
    } else {
        std::cerr << "Failed to initialize CURL.\n";
        return false;
    }
}

// Extract the filename from the URL
std::string extractFilename(const std::string& url) {
    size_t pos = url.find_last_of('/');
    if (pos != std::string::npos) {
        return url.substr(pos + 1);
    }
    return url; // Return the URL if no '/' is found
}

int main() {
    const std::string baseUrl = "https://ecomusnext-themesflat.vercel.app/images/shop/gallery/gallery-";
    const std::string extension = ".jpg";

    for (int i = 2; i <= 24; ++i) {
        std::string url = baseUrl + std::to_string(i) + extension;
        std::string outputFilename = extractFilename(url); // Extract filename from URL

        std::cout << "Downloading: " << url << "\n";
        if (downloadImage(url, outputFilename)) {
            std::cout << "Downloaded successfully: " << outputFilename << "\n";
        } else {
            std::cerr << "Failed to download: " << url << "\n";
        }
    }

    return 0;
}
