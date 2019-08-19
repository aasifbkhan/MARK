#include <sapi.h>
#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main()
{
	string str;
	string fcp;
	Mat image;
	ISpVoice* pVoice = NULL;
	CascadeClassifier faceCascade;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;
	
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)& pVoice);
	if (SUCCEEDED(hr))
	{
			cout << "\n                                                  Hello Everyone..!" << endl;
			hr = pVoice->Speak(L"\n Hello Everyone..!", SPF_IS_XML, NULL);
			cout << "                           I'm Ultron The Image Processing Program." << endl;
			hr = pVoice->Speak(L"I'm Ultron The Image Processing Program.", SPF_IS_XML, NULL);
			cout << "\n-->> Enter The Path Of Your Image" << endl;
			hr = pVoice->Speak(L"Enter The Path Of Your Image", SPF_IS_XML, NULL);
			getline(cin,str);
			image = imread(str);
			if (image.empty()) {
				cout << "Oops..! Image Is Not Found"<<endl;
				hr = pVoice->Speak(L"Oops..! Image Is Not Found", SPF_IS_XML, NULL);
				return -1;
			}
			cout << " I Found Image..!!!";
			hr = pVoice->Speak(L"I Found Image..!!!", SPF_IS_XML, NULL);
			fcp = "opencv-master/data/haarcascades/haarcascade_frontalface_alt.xml";
			faceCascade.load(fcp);
			vector<Rect> faces;
			faceCascade.detectMultiScale(image, faces);








			namedWindow("image", WINDOW_NORMAL);
			imshow("image", image);
			waitKey(0);

			pVoice->Release();
			pVoice = NULL;
	}

	::CoUninitialize();
	return TRUE;
}