program Lab2;

uses
    System.SysUtils;

var
    V, D, R: Real;
    N, I: Integer;

begin
    N := 12;
    D := 10;
    R := D / 2;
    Writeln('���������� ��������� ����� (�) 12 ��������� ���� � ����� �����  ��  �������� 5 ��.');
	  Writeln('���������� ������� ����������� ���� ����� 10 ��. �������, ��� ���� ������������ ����');
    Writeln('� ����� ��� �������.');
    for I := 1 to N do
    begin
        R := R + 0.5;
    end;
    V := 4 / 3 * PI * R * R * R / 1000;
    Writeln('��������� ����� = ', V:1:3, '(�)');
    Readln;
end.