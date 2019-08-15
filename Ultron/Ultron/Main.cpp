#include <sapi.h>
#include<iostream>

using namespace std;

int main()
{
	char ch[1000];
	int a;
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
			if (ch == "image detection" || ch == "image processing" || ch == "object detection" || ch=="video detection") {
				hr = pVoice->Speak(L"Select anyone from the video.", SPF_IS_XML, NULL);
				cout << "\n 1. Object Detection Using Image.\n 2. Object Detection Using Video."<<endl;
				cin >> a;
				switch (a)
				{
				case 1:
					cout << "You are in case one";
					break;
				case 2:
					cout << "you are in case two";
					break;
				default:
					break;
				}
			}
			pVoice->Release();
			pVoice = NULL;
		} while (ch=="stop");
	}

	::CoUninitialize();
	return TRUE;
}