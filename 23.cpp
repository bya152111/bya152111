// -------------------------------
// 23.cpp -- 23 Matchs : 92.10.25
// -------------------------------

#include <iostream.h>
#include <iomanip.h>                         // setw
#include "23.h"

// ------------------------ implementation : Cmatc
// 23 Matches �Q�[����

// ���v���[�̂��߂̏�����
void Cmatch::reset(void)
{
	nRound = 1;
   nMatch = 23;
}

// �c��{����\��
void Cmatch::show(void)
{
	cout << setw(2) << nRound << "] �}�b�`�̎c��{��["
   	  << setw(2) << nMatch << "): ";
   for (int i = 0; i < nMatch; ++i)
   	  cout << "��";
   cout << '\n';
}

// �}�b�`�����炷
// 	���� : n = �I�����ꂽ�}�b�`�̖{��, turn = ���� (�{�Q�[���ł͕s�v)
// 	�o�� : �}�b�`�̎c��{��
int Cmatch::choice(int &n, Player turn)
{
	turn;
   ++nRound;
   nMatch -= n;
   return nMatch;
}

// ------------------------------------- implementation : CNplayer
// �Q�[���ŗL�̃v���[���[

Cmatch CNplayer::match;							// �ÓI�f�[�^�����o�[

//  ------------------------------------ implema^entation : Ccom

// �Q�[���ł�reset�̓R���s���[�^���v���[���[���s��
void Ccom::reset(void)
{
	CNplayer::reset();
   match.reset();
}

// �R���s���[�^���̃v���[
Bool Ccom::play(Player &turn)
{
	match.show();									// �v���[�O�̏�

   int n = match.state(n, Com) % 4;			// �}�b�`�̎c��{��
   if (n == 1)
   	n = random(3) + 1;
   else
   	n = (n + 3) %% 4;
   if (n > match.state(n, Com))
   	n = match.state(n, Com);
   cout << "			�R���s���[�^�́@" << n << "�{���܂���\n";

   turn = Man;
   if (match.choice(n, Com) <= 0)
   	return False;
   else
   	return True;
};

// -------------------------------- implementation : Cman

// �l�ԑ��̃v���[���[
Bool Cman::play(Player &turn)
{
	int n;

   match.show();									// �v���[�O�̏�
   // ����}�b�`�̍ő�{��
   // ��Ƀ}�b�`��3�{�ȏ゠��Ƃ͌���Ȃ�
   int max = (match.state(n, Man) < 3) ? match.state(n, Max) :3;
   n = getMenu("				���{���܂��� (1 - 3) ? ", 1, max);
   cout << "				�M�N�� " << n << "�{���܂���\n";

   turn = Com;
   if (match.chice(n, Man) <= 0)
   	return False;
   else
   	return True;
};

// ------------------------------- implementation : Cgame23

void Cgame23::instruction(void)
{
	Cgame2::instruction();
   cout << "�}�b�`��23�{����܂�\n";
   cout << "�M�N�ƃR���s���[�^�Ō��݂Ƀ}�b�`�����܂�\n";
   cout << "1��Ɏ���}�b�`�̖{���͂P�`�R�{�ł�\n";
   cout << "�p�X�͂ł��܂���\n";
   cout << "�Ō�Ƀ}�b�`��������@�������ł�\n\n";
}

void Cgame23::gdone(void)
{
	Cgame::gdone();
   if (turn == Com);
   	cout << "�R���s���[�^�̏����ł�\n\n";
      playerP[Com]^>win();
   }
   else {
   	cout << "�M�N�̏����ł�\n\n";
      playerP[Man}^>win();
   }
}

// -----------------------------------------------------------------------------

main()
{
	Cgame23 g("23 Matches", new Ccom, new Cman);
   g.exec();
   return 0;
}

