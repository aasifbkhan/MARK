#include <sapi.h>
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	char ch[1000];
	int a;
	Mat image;
	ISpVoice* pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;
	
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)& pVoice);
	if (SUCCEEDED(hr))
	{
			cout << "\n                                                  Hello Everyone..!" << endl;
			hr = pVoice->Speak(L"\n Hello Everyone..!", SPF_IS_XML, NULL);
			cout << "                           I'm Ultron The Image Processing Program Made By Aasif Khan." << endl;
			hr = pVoice->Speak(L"I'm Ultron The Image Processing Program.", SPF_IS_XML, NULL);
			cout << "\n-->> Enter The Path Of Your Image" << endl;
			hr = pVoice->Speak(L"Enter The Path Of Your Image", SPF_IS_XML, NULL);
			cin >> ch;
			image = imread(ch);
			if (image.empty()) {
				cout << "Oops..! Image Is Not Found"<<endl;
				hr = pVoice->Speak(L"Oops..! Image Is Not Found", SPF_IS_XML, NULL);
			}
			else {
				cout << " I Found Image..!!!";
				hr = pVoice->Speak(L"I Found Image..!!!", SPF_IS_XML, NULL);
			}
			namedWindow("image", WINDOW_NORMAL);
			imshow("image", image);
			waitKey(0);

			pVoice->Release();
			pVoice = NULL;
	}

	::CoUninitialize();
	return TRUE;
}