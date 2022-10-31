Program Lab_2_2;

Type
    TArr = array[1..100] of Integer;

Function FindNum: TArr;
Const Factor = 2;
Var
    H, M, I: Integer;
    Num: TArr;
Begin
    I := 0;
    H := 2;
    M := 0;
    Repeat
        H := H * Factor + M;
        If H < 10 Then
            M := 0
        Else
        Begin
            H := H - 10;
            M := 1;
        End;
        Inc(I);
        Num[I] := H;
    Until (H = 2) And (M = 0);
    Result := Num;
End;

Procedure PrintArr(Num: TArr);
Var
    K: Integer;
Begin
    Writeln('����������� �����: ');
    For K := 18 DownTo 1 Do
        Write (Num[K]);
End;

Begin
    PrintArr(FindNum);
    Readln;
End.
