#include <sapi.h>
#include<iostream>

using namespace std;


int main(int argc, char* argv[])
{
	char ch[1000];
	ISpVoice* pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)& pVoice);
	if (SUCCEEDED(hr))
	{
		do {
			cout << "\n                                                  Hello Everyone..!" << endl;
			hr = pVoice->Speak(L"\n Hello Everyone..!", SPF_IS_XML, NULL);
			cout << "                           I'm Ultron The Image Processing Program Made By Aasif Khan." << endl;
			hr = pVoice->Speak(L"I'm Ultron The Image Processing Program Made By Aasif Khan", SPF_IS_XML, NULL);
			cout << "\n-->> What can i help you?" << endl;
			hr = pVoice->Speak(L"What can i help you?", SPF_IS_XML, NULL);
			cin >> ch;







			pVoice->Release();
			pVoice = NULL;
		} while (ch=="stop");
	}

	::CoUninitialize();
	return TRUE;
}