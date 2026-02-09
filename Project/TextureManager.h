#pragma once
#include "string"
#include <dxgi1_6.h>      // DXGI_FORMAT 等
#include <vector>
#include <algorithm>
#include <cassert>
#include "externals/DirectXTex-mar2023/DirectXTex/DirectXTex.h"

#include <wrl.h>          // ComPtr
#include <d3d12.h>        // ID3D12Resource


using Microsoft::WRL::ComPtr;

class DirectXCommon;

class TextureManager 
{
public:


	D3D12_GPU_DESCRIPTOR_HANDLE GetSrvHandleGPU(uint32_t index);




	// テクスチャ1枚分のデータ
	struct TextureData
	{
		std::string filePath;
		DirectX::TexMetadata metadata;

		ComPtr<ID3D12Resource> resource;
		ComPtr<ID3D12Resource> intermediateResource;
		D3D12_CPU_DESCRIPTOR_HANDLE srvHandleCPU{};
		D3D12_GPU_DESCRIPTOR_HANDLE srvHandleGPU{};
	};

	
	

	// 初期化
	void Initialize(DirectXCommon* dxCommon_);
	// シングルトンインスタンスの取得
	static TextureManager* GetInstance();
	// 終了
	void Finalize();

	// テクスチャファイルの読み込み
	void LoadTexture(const std::string& filePath);
	// SRVインデックスの開始番号
	uint32_t GetTextureIndexByFilePath(const std::string& filePath);
	// テクスチャ番号からGPUハンドルを取得
	//D3D12_GPU_DESCRIPTOR_HANDLE GetSrvHandleGPU(uint32_t textureIndex);
	// メタデータ取得
	const DirectX::TexMetadata& GetMetaData(uint32_t textureIndex);


private:

	// テクスチャデータ
	std::vector<TextureData> textureDatas;

	static TextureManager* instance;
	// SRVインデックスの開始番号
	static uint32_t kSRVIndexTop;

	DirectXCommon* dxCommon = nullptr;

	TextureManager() = default;
	~TextureManager() = default;
	TextureManager(TextureManager&) = delete;
	TextureManager& operator=(TextureManager&) = delete;
};