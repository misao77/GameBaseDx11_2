#pragma once
#include "Engine//GameObject.h"
class Enemy :
    public GameObject
{
public:
	Enemy(GameObject* parent);
	~Enemy();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	void OnCollision(GameObject* pTarget);
private:
	int hModel_;//モデルのハンドル
	//Transform tr_;// トランスフォーム
};

