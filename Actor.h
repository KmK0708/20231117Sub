#pragma once
class AActor
{
public:
		AActor();
		virtual ~AActor();
		// ������ ��� ����
		// int X, Y;
		// BeginPlay();
		virtual void BeginPlay() = 0;
		// Tick();
		virtual void Tick() = 0;
		// Render();
		virtual void Render() = 0;
		// �Լ��� = 0 ���̸� ���� �����Լ��� ��
		// ���� �����Լ��� �����ΰ� ����
		// ���� �����Լ��� �ϳ��� ������ �ִ� Ŭ������
		// �߻� Ŭ������ ��
		// �߻� Ŭ������ ��ü�� ���� �� ����

};

