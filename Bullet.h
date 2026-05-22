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
private:
	int hModel_;//モデルのハンドル
	Transform tr_;// トランスフォーム
	float speed_;//弾の速さ
};

