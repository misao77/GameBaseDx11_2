#pragma once
#include "Engine//GameObject.h"

// クラス名を EnemyBullet に変更
class EnemyBullet : public GameObject
{
public:
    EnemyBullet(GameObject* parent);
    ~EnemyBullet();

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

private:
    int hModel_;          // モデルのハンドル
    Transform tr_;    // Bullet.h にありますが、親の transform_ を使っているなら不要かも？一応残してもOK
    float speed_;         // 弾の速さ
};

