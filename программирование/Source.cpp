#include<iostream>
#include<string>
#include<bitset>

//�������� ���� �� ���� ���, ����������� �� ���, � 1 �����:
enum OBJECT_ATTRIBUTE : uint8_t {                       //�������� �������
	DESTROYABLE = 1<<0,             // 0000 0001       //����������� ������ ��� ���
	MOVABLE     = 1 << 1,          // 0000 0010       //����� ������� ��� ���
	TRANSPARENT = 1 << 2,         // 0000 0100       //���������� ��� ���
	IS_LIGHT    = 1 << 3,        // 0000 1000       //�������� �� �� ������ ��� ���
	HAS_SHADOWS = 1 << 4,                          //����� �� �� ����
	RESERVED_1  = 1 << 5,                         //��������� 
	RESERVED_2  = 1 << 6,                        //��������� 
	RESERVED_3  = 1 << 7                        //��������� 
};
int main()
{
	uint8_t objectDescription = 0;      //�������� �������
	//��������� �����:
	objectDescription |= IS_LIGHT | MOVABLE;  //�������� ������ � �� �������� ������ � ��� ����� �������
	  
	//����������� ����� 0000 1000
	//	      � ���     0000 0010    
	//	       �������� 0000 1010 ���� �� ������������, ��������������� ����, ������� ��� � �����
	//	� 1 ����� ����� ��������� ������ ��������.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	uint8_t objectDescription2 = DESTROYABLE;
	objectDescription2 |= IS_LIGHT | MOVABLE;

	//����������� ��� �����
	//  0000 0001
	//	0000 0010
	//	0000 1000
	//	�������� = 0000 1011

	//�������� ������ �������� �������� ��� ������:
	bool isDestroyble = objectDescription2 & DESTROYABLE;  //��������� ����������� �� ��� ������ �������� �-& ������� ����� DESTROYABLE

	//	���� �� �������� ��� ����� & DESTROYABLE ����� (�&) ��
	//	&0000 0001
	//	�������� ��� ��� ������� ������������ ����� ����� 
	//	= 0000 0001 ����� ��� �.� �� ����� ���� � ������ ����� DESTROYABLE ����

	bool isLight = objectDescription & IS_LIGHT;            //��������� ���� �� ����
	bool hasShadows = objectDescription & HAS_SHADOWS;     //��������� ���� �� ����

		//������� �� �����:
	std::cout << isDestroyble << std::endl;
	std::cout << isLight << std::endl;
	std::cout << hasShadows << std::endl;
	// 1- yes, 0-no

	getchar();
	return 0;
}