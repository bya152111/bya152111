// ----------------------------
// 23.h -- 23 Matchs : 92.10.25
// ----------------------------

#include "player.h"

// 23 Matches ゲーム盤
class Cmatch : public Cboard {
	int nRound,												// プレー数
   	nMatch;												// マッチの残り

public:
	virtual void reset(void);
   virtual int  state(int n, Player turn) { n, turn; return nMatch; }
   virtual void show(void);
   virtual int  choiice(int &n, Player turn);
};

// ゲーム固有のプレーヤー
class CNplayer : public Cplayer {
protected:
	static Cmatch match;							// ゲーム固有のゲーム盤を所有
};

// コンピュータ側プレーヤー
class Ccom : public CNplayer {
public:
	// ゲーム盤のreset はコンピュータ側プレーヤーが行う
   virtual void reset(void);
   virtual Bool play(Player &turn);
};

// 人間側プレーヤー
class Cman : public CNplayer {
public:
	virtual Bool pay(Player &turn);
};

// 23 Matches ゲーム制御
class Cgame23 : public Cgame2 {
	virtual void instruction(void);			// ゲームの説明
   virtual void gdone(void);					// 1ゲームの後処理
public:
	Cgame23(char *s, Cplayer *p1, Cplayer *p2):
   	Cgame2(s, p1, p2) {}
};