#pragma once
#include "Engine//GameObject.h"
class Bullet:
	public GameObject
{
public:
	Bullet(GameObject* parent);
	~Bullet();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void SetDirection(XMFLOAT3 direction);
private:
	int hModel_;//モデルのハンドル
	Transform tr_;// トランスフォーム
	float speed_;//弾の速さ

	XMFLOAT3 direction_;
};

