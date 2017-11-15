// tts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sapi.h>

int main(int argc, char * argv[])
{
	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		if (argc == 2) {
			wchar_t text[4096]{ 0 };
			MultiByteToWideChar(CP_ACP, 0, argv[1], -1, text, 4096);
			hr = pVoice->Speak(text , 0, NULL);
		}
		pVoice->Release();
		pVoice = NULL;
	}

	::CoUninitialize();
	return TRUE;
}