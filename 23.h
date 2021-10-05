// ----------------------------
// 23.h -- 23 Matchs : 92.10.25
// ----------------------------

#include "player.h"

// 23 Matches �Q�[����
class Cmatch : public Cboard {
	int nRound,												// �v���[��
   	nMatch;												// �}�b�`�̎c��

public:
	virtual void reset(void);
   virtual int  state(int n, Player turn) { n, turn; return nMatch; }
   virtual void show(void);
   virtual int  choiice(int &n, Player turn);
};

// �Q�[���ŗL�̃v���[���[
class CNplayer : public Cplayer {
protected:
	static Cmatch match;							// �Q�[���ŗL�̃Q�[���Ղ����L
};

// �R���s���[�^���v���[���[
class Ccom : public CNplayer {
public:
	// �Q�[���Ղ�reset �̓R���s���[�^���v���[���[���s��
   virtual void reset(void);
   virtual Bool play(Player &turn);
};

// �l�ԑ��v���[���[
class Cman : public CNplayer {
public:
	virtual Bool pay(Player &turn);
};

// 23 Matches �Q�[������
class Cgame23 : public Cgame2 {
	virtual void instruction(void);			// �Q�[���̐���
   virtual void gdone(void);					// 1�Q�[���̌㏈��
public:
	Cgame23(char *s, Cplayer *p1, Cplayer *p2):
   	Cgame2(s, p1, p2) {}
};