#pragma once
#include"Windows.h"
#include"cstdint"

//WindowsAPI
class WinApp
{
public:
	
	
	

	static LRESULT CALLBACK WindowProc
	(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
	//クライアント領域のサイズ
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;

	void Initialize();
	void Update();

	HINSTANCE GetHInstance()const { return wc.hInstance; }
	HWND GetHwnd()const { return hwnd; }
	
	//終了処理
	void Finalize();

	//メッセージの処理
	bool ProceccMassage();

private:
	//ウインドウハンドル
	HWND hwnd = nullptr;

	//ウインドウクラスの設定
	WNDCLASS wc{};
};

