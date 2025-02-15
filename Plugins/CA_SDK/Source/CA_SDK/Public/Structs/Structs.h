// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Structs.generated.h"

	/**
	 * Structs for DTOs
	 */
	USTRUCT(BlueprintType)
		struct FLoginRequestDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString email;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString password;
	};
	USTRUCT(BlueprintType)
		struct FLoginMetamaskDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString wallet;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString signature;
	};
	USTRUCT(BlueprintType)
		struct FLoginResponseDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString userId;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString wallet;
	};
	USTRUCT(BlueprintType)
		struct FDefaultSearchAvatarsDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString license;
	};
	USTRUCT(BlueprintType)
		struct FSearchAvatarByNameDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString name;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString license;
	};
	USTRUCT(BlueprintType)
		struct FOwnerAvatarsDto
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString owner;
	};
	USTRUCT(BlueprintType)
		struct FOwnerAvatarsDtoCollectionName
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString collectionName;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString owner;
	};
	USTRUCT(BlueprintType)
		struct FDefaultSearchAvatarsDtoCollectionName
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString collectionName;
	};
	USTRUCT(BlueprintType)
	struct FMetadataAvatar {
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString name;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString description;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString image;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString asset;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString createdBy;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString createdAt;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			TArray<FString> tags;
		FMetadataAvatar() {
			name = "";
			description = "";
			image = "";
			asset = "";
			createdBy = "";
			createdAt = "";
			tags = TArray<FString>();
		}
	};
	USTRUCT(BlueprintType)
		struct FAvatar
	{
		GENERATED_BODY()
	public:
	
		FMetadataAvatar metadata;
	};
	USTRUCT(BlueprintType)
		struct FAvatarsArray
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			TArray<FAvatar> avatars;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString license;
	};
	USTRUCT(BlueprintType)
		struct FMetadataNft {
		GENERATED_BODY()
		public:
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString name;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString description;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString image;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString asset;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString createdy;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString createdAt;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				TArray<FString> tags;
			FMetadataNft() {
				name = "";
				description = "";
				image = "";
				asset = "";
				createdy = "";
				createdAt = "";
				tags = TArray<FString>();
			}
	};
	USTRUCT(BlueprintType)
		struct FNft
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString owner;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
		FMetadataNft metadata;
	};
	USTRUCT(BlueprintType)
		struct FNftsArray
	{
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			TArray<FNft> nfts;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			int32 totalNfts;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			int32 currentPage;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			int32 totalPages;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString next;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString prev;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			int totalItemsCount;
		FNftsArray() {
			nfts = TArray<FNft>();
			totalNfts = 0;
			currentPage = 0;
			totalPages = 0;
			next = "";
			prev = "";
		}
	};
	USTRUCT(BlueprintType)
	struct FCollectionContracts {
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString contractAddress;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString chainId;
	};
	USTRUCT(BlueprintType)
	struct FSocialLinks {
		GENERATED_BODY()
	public:
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString twitter;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString website;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString discord;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString instagram;
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FString twitch;
	};
	USTRUCT(BlueprintType)
		struct FNftsCollection {
		GENERATED_BODY()
		public:
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				bool isEnabled;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString logoImage;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString bannerImage;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString id;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString name;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FCollectionContracts collectionContracts;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 __v;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 owners;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString description;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			FSocialLinks socialLinks;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 totalSupply;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 floorPrice;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 volume;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				int32 bestOffer;
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
				FString mobileBannerImage;
			FNftsCollection() {
				isEnabled = false;
				logoImage = "";
				bannerImage = "";
				id = "";
				name = "";
				__v = 0;
				owners = 0;
				description = "";
				totalSupply = 0;
				floorPrice = 0;
				volume = 0;
				bestOffer = 0;
				mobileBannerImage = "";
			}

		
	};
	
	USTRUCT(BlueprintType)
		struct FNftsCollectionsArray {
		GENERATED_BODY()
		public:
			UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Structs")
			TArray<FNftsCollection> collections;
	};