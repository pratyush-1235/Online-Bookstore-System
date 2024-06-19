#include<iostream>
#include<string>
using namespace std;
class book {
private:
    string author, title, publisher;
    float price;
    int stock;
public:
    book() {
        price = 0.0f;
        stock = 0;
    }
    void feeddata();
    void editdata();
    void showdata();
    bool search(const string& tbuy, const string& abuy);
    void buybook();
};

void book::feeddata() {
    cin.ignore();
    cout << "\nEnter Author Name: ";    getline(cin, author);
    cout << "Enter Title Name: ";       getline(cin, title);
    cout << "Enter Publisher Name: ";   getline(cin, publisher);
    cout << "Enter Price: ";            cin >> price;
    cout << "Enter Stock Position: ";   cin >> stock;
}

void book::editdata() {
    cout << "\nEnter Author Name: ";    getline(cin, author);
    cout << "Enter Title Name: ";       getline(cin, title);
    cout << "Enter Publisher Name: ";   getline(cin, publisher);
    cout << "Enter Price: ";            cin >> price;
    cout << "Enter Stock Position: ";   cin >> stock;
}

void book::showdata() {
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << price;
    cout << "\nStock Position: " << stock;
}

bool book::search(const string& tbuy, const string& abuy) {
    return (tbuy == title && abuy == author);
}

void book::buybook() {
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;
    if (count <= stock) {
        stock -= count;
        cout << "\nBooks Bought Successfully";
        cout << "\nAmount: $" << price * count;
    }
    else
        cout << "\nRequired Copies not in Stock";
}

int main() {
    book* B[20];
    int i = 0, choice;
    string titlebuy, authorbuy;
    while (1) {
        cout << "\n\n======ONLINE BOOK STORE======"
            << "\n1. Entry of New Book"
            << "\n2. Buy Book"
            << "\n3. Search For Book"
            << "\n4. Edit Details Of Book"
            << "\n5. Exit"
            << "\n\nEnter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            B[i] = new book;
            B[i]->feeddata();
            i++;
            break;

        case 2:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; getline(cin, titlebuy);
            cout << "Enter Author Of Book: "; getline(cin, authorbuy);
            for (int t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    B[t]->buybook();
                    break;
                }
                if (t == i - 1)
                    cout << "\nThis Book is Not in Stock";
            }
            break;

        case 3:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; getline(cin, titlebuy);
            cout << "Enter Author Of Book: "; getline(cin, authorbuy);
            for (int t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->showdata();
                    break;
                }
                if (t == i - 1)
                    cout << "\nThis Book is Not in Stock";
            }
            break;

        case 4:
            cin.ignore();
            cout << "\nEnter Title Of Book: "; getline(cin, titlebuy);
            cout << "Enter Author Of Book: "; getline(cin, authorbuy);
            for (int t = 0; t < i; t++) {
                if (B[t]->search(titlebuy, authorbuy)) {
                    cout << "\nBook Found Successfully";
                    B[t]->editdata();
                    break;
                }
                if (t == i - 1)
                    cout << "\nThis Book is Not in Stock";
            }
            break;

        case 5:
            for (int t = 0; t < i; t++) {
                delete B[t];
            }
            exit(0);
            break;

        default:
            cout << "\nInvalid Choice Entered";
        }
    }

    return 0;
}