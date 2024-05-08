#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MediaType {
protected:
    string name;
    string dateCreated;
    int size;

public:
    MediaType(string name, string dateCreated, int size) : name(name), dateCreated(dateCreated), size(size) {}

    string getName() const {
        return name;
    }

    virtual void displayInfo() = 0;
};

class Image : public MediaType {
private:
    string format;

public:
    Image(string name, string dateCreated, int size, string format) : MediaType(name, dateCreated, size), format(format) {}

    void displayInfo() override {
        cout << "Image Name: " << name << endl;
        cout << "Date Created: " << dateCreated << endl;
        cout << "Size: " << size << " KB" << endl;
        cout << "Format: " << format << endl;
    }
};

class Video : public MediaType {
private:
    string format;

public:
    Video(string name, string dateCreated, int size, string format) : MediaType(name, dateCreated, size), format(format) {}

    void displayInfo() override {
        cout << "Video Name: " << name << endl;
        cout << "Date Created: " << dateCreated << endl;
        cout << "Size: " << size << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

class MediaSharing {
public:
    void shareViaBluetooth(MediaType* media) {
        cout << "Sharing " << media->getName() << " via Bluetooth" << endl;
    }

    void shareViaMail(MediaType* media) {
        cout << "Sharing " << media->getName() << " via Mail" << endl;
    }

    void shareViaWhatsApp(MediaType* media) {
        cout << "Sharing " << media->getName() << " via WhatsApp" << endl;
    }
};

int main() {

    Image image1("Nature", "2024-05-07", 1024, "JPEG");
    Video video1("Vacation", "2024-05-07", 2048, "MP4");

    MediaSharing mediaSharing;
    mediaSharing.shareViaBluetooth(&image1);
    mediaSharing.shareViaMail(&video1);
    mediaSharing.shareViaWhatsApp(&image1);

    cout << "\nImage Information:" << endl;
    image1.displayInfo();
    cout << "\nVideo Information:" << endl;
    video1.displayInfo();

    return 0;
}
