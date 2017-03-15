#include "AddressBook.h"
using namespace std;
int main() {
    CAddressBook* pDevice = new CAddressBook();
	pDevice->Run();
    delete pDevice;
    return 0;
}