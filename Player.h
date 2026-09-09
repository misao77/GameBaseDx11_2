#pragma once
#include "Engine//GameObject.h"
#include "Bullet.h"

class Player :
	public GameObject
{
public:

	Player(GameObject* parent);
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
private:
	int hModel_;//モデルのハンドル
	Transform tr_;//トランスフォーム
};

