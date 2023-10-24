#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <string>
#include <random>
#include <set>
#include <queue>

using namespace std;

float Random(int i)
{
    float ans = 0;

    srand(time(NULL));
    
    ans = rand() % i;

    return ans;
};
class parent
{
public:
    parent()
    {
        cout << " parent create " << endl;
    }

    virtual void pv()
    {
        cout << "parent" << endl;
    }
};

class child : public parent
{
public:
    child()
    {
        cout << " child create " << endl;
    }

    virtual void pv()
    {
        cout << "child" << endl;
    }
};
struct FloatXY
{
    float x;
    float y;

    FloatXY(float a, float b)
    {
        x = a;
        y = b;
    }
};

void Test1()
{
    int n = 360;
    float x = 0, y = 0;
    float theta = 0, radius = 0.5f;
    vector<FloatXY> vertices;
    FloatXY center = FloatXY(0.0f, 0.0f);

    for (int i = 0; i < n; i++)
    {
        float temp = cos(theta);
        float temp2 = sin(theta);
        x = cos(theta) * radius + center.x;
        y = sin(theta) * radius + center.y;

        vertices.emplace_back(x, y);

        theta -= (360 / n);

        x = cos(theta) * radius + center.x;
        y = sin(theta) * radius + center.y;
        float demp = cos(theta);
        float demp2 = sin(theta);

        vertices.emplace_back(x, y);

        vertices.emplace_back(center.x, center.y);
    }
}

void PointTest()
{
    int i = 1;
    int* p = &i;
    int* p2 = p;
    int** pp = &p;

    cout << "i: " << i << endl;
    cout << "&i: " << &i << endl;

    cout << "\np: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "&p: " << &p <<  endl;
    cout << "&(*p): " << &(*p) << endl;

    cout << "\n p2: " << p2 << endl;
    cout << "*p2: " << *p2 << endl;
    cout << "&p2: " << &p2 << endl;
    cout << "&(*p2): " << &(*p2) << endl;

    cout << "\n pp: " << pp << endl;
    cout << "*pp: " << *pp << endl;

    /*
        ������:
            - ������ �ּҰ��� �����ϴ� ����

        �׽�Ʈ ����: ���� ���� �����͸� ����� �ʿ䰡 �ִ°�?

        ����Ʈ �ϳ� �� ���� p2 = p �ϸ� ���� ���� ����Ű�µ�.
    */
}

void RangeFor()
{
    vector<int> a;
    
    for(int i = 0; i < 5; i++)
        a.push_back(i);

    for(int i : a)
        cout << i << endl;

    for (int i : a)
        i = 10;

    for (int i : a)
        cout << i << endl;

    vector<int*> b;

   // for(int*& i : b)
    //{
    //    i = new int(1);
    //}

    for(int* i : b)
        *i = 10;

    for(int* i : b)
        cout << *i << endl;

}

class TestVirtualFunctionParent
{
public:
    TestVirtualFunctionParent(){cout << "p ������" << endl;};
    ~TestVirtualFunctionParent(){};

    virtual void test(){ cout << "parent"<< endl;}
};

class TestVirtualFunctionChild1 : public TestVirtualFunctionParent
{
public:
    TestVirtualFunctionChild1(){ cout << "c1 ������" << endl; };
    ~TestVirtualFunctionChild1(){};
    virtual void test() { cout << "child1" << endl; }
};

class TestVirtualFunctionChild2 : public TestVirtualFunctionParent
{
public:
    TestVirtualFunctionChild2() { cout << "c2 ������" << endl; };
    ~TestVirtualFunctionChild2() {};
    virtual void test() { cout << "child2" << endl; }
};


void staircase(int n) {
    for (int i = 0; i < n; i++)
    {
        // 3 2 1 0
        //                 4 - 1 2 3 4
        for (int j = 0; j < n - (1 + i); j++)
            cout << "1";

        // 1 2 3 4
        // 4 - 3 = 1
        // 4 - 2 = 2
        // 4-  1 = 3

        //              1. 4 - 3 ( n - i + 1)
        //              2. 4 - 2     
        //              3. 4 - 1
        //              4. 4 - 0
        for (int k = 0; k < n - (n - (i + 1)); k++)
            cout << "#";

        cout << endl;
    }

}

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    long long maxSum = 0;
    long long minSum = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        minSum += arr[i];
    }

    for (int i = 1; i < arr.size(); i++) 
    {
        int temp =arr[i];
        maxSum += temp;
    }

    cout << minSum << " " << maxSum;
    /*
        vector<int> test;
    test.push_back(256741038);
    test.push_back(623958417);

    test.push_back(467905213);
    test.push_back(714532089);
    test.push_back(938071625);

    miniMaxSum(test);
    */
}

bool table[10001] = { false, };

int d(int inputNum)
{
    int num = inputNum;

    while (inputNum > 0)
    {
        num += inputNum % 10;
        inputNum /= 10;
    }

    return num;
}

void SelfNumber()
{
    int num = 0;
    for (int i = 1; i < 10001; i++)
    {
        num = d(i);
        if( num < 10001) table[num] = true;
    }

    for(int i = 1; i < 10001; i++)
    {
        if(!table[i]) cout << i << endl;
    }
}

void HanSu()
{
    /*
        ����
            � ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�.
        ���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. N�� �־����� ��,
        1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
        

        �Է�
            ù° �ٿ� 1,000���� �۰ų� ���� �ڿ��� N�� �־�����.
        
        ���
            ù° �ٿ� 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����Ѵ�.

        �Է�    ���
        --------------------
        110     99
        1       1
        210     105
        1000    144
        500     119
    */
    using namespace std;
    
    int inputNum;
    cin >> inputNum;

    // 100 �̸��̸�, ���� �״�� ���
    if(inputNum < 100)
    {
        cout << inputNum << endl;
        return;
    }

    // 100 �̻��̶��

    int ans = 99;
    // 123, 2- 1, 3 - 2
    // 10�� �ڸ� - 100�� �ڸ�  , 1���ڸ� - 10�� �ڸ�
    // �߰� - ��, �� - �߰�
    // 123 % 10 = 3
    // 123 % 100 = 23
    // 12 % 10 = 2

    // ����.
    //      100���� ~ N���� ++�ϸ鼭 ������ �� ������.
    //      1. 100�� 1���� �ɰ��� �μ��� �־��ش�.
    //      2. ���� �μ����� ������ �ؼ� �´��� Ȯ���Ѵ�.
    //      3. �����ϸ� ans++,
    //      4. �׸��� 100++�� ���ش�.
    if(inputNum == 1000) inputNum = 999;

    int countNum = 100;
    while(countNum <= inputNum)
    {
        int temp = countNum;

        int one     = temp % 10;
        temp /= 10;

        int ten     = temp % 10;
        temp /= 10;

        int hund   = temp % 10;

        if((ten - hund) == (one - ten)) ans++;

        countNum++;
    }
    
    cout << ans << endl;
}

void PrintASCII()
{
    char ch;
    cin >> ch;

    printf("%d", ch);
    //cout << (int)ch;
}

void PrintNumbersSum()
{
    using namespace std;

    int first = 0;
    string second;

    cin >> first;       // 1 <= N <= 100, ������ ����
    cin >> second;      // ���� N���� ������� �־�����.
    
    int ans = 0;

    for(int i = 0; i < first; i++)
    {
       ans += (second[i] - '0');
    }
    
    // print: �Է����� �־��� ���� N���� ��
    cout << ans << endl;
}

void TimeSplit()
{
    
string s = "91:23:45AM";

int hh = (s[0] - '0') * 10 + (s[1] - '0');

//int b = a[0] - '0' * 10;
//int c = a[1] - '0';

printf("%02d", hh);

//cout << hh << endl;

}

void FindABC()
{
    using namespace std;

    string s;
    cin >> s;

    vector<int> arr(26);

    // 26�� ���� -1 �ʱ�ȭ
    for(int i = 0; i < arr.size(); i++) arr[i] = -1;

    for(int i = 0; i < s.size(); i++)
    {
        int temp = s[i] - 'a';

        if(arr[temp] > -1) continue;
        arr[temp] = i;
    }
    
    for(int i = 0; i< arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void StringRoop()
{
    using namespace std;
    
    int testCase = 0;
    int roop = 0;
    string s;

    cin >> testCase;
    for(int i = 0; i < testCase; i++)
    {
        cin >> roop;
        cin >> s;

        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < roop; j++)
            {
                ans += s[i];
            }
        }

        cout << ans << endl;
    }

}

void WordStudy()
{
    /*
        ����
            ���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, 
            �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
            ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.
        
        �Է�
            ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����.
            �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.
        
        ���
            ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�.
            ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
        
        ���� �Է� 1     ���� ��� 1
        Mississipi     ?

        ���� �Է� 2     ���� ��� 2 
        zZa            Z

        ���� �Է� 3     ���� ��� 3 
        z              Z

        ���� �Է� 4     ���� ��� 4 
        baaa           A
    */

    using namespace std;

    int arr[26] = {0,};
    string ans = "";
    string InputS = "";

    cin >> InputS;
    
    for(int i = 0; i < InputS.size(); i++)
    {
        int temp = InputS[i];

        if(temp < 97) 
        {
            InputS[i] = char(temp + 32);
            temp += 32;
        }

        arr[temp - 'a'] ++;
    }


    // ī��Ʈ �ؼ� ���� ���� ���� ���ĺ� ã�� ��.
    int maxNum = 0;         // �ִ� ��
    for(int i = 0; i < 26; i++)
    {
        if(maxNum < arr[i])
        {
            maxNum = arr[i];
            ans = char(i + 'A');
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if(maxNum == arr[i]) count++;
    }

    if (count >= 2) ans = '?';

    cout << ans << endl;

    // space    32
    //  a       97
    //  A       65
    //cout << (int)'a'<< endl;
    //cout << (int) ' ' << endl;
    //cout << char('A' + ' ') << endl;
}

void WordCount()
{
    using namespace std;

    string inputS;
    int count = 0;

    while (cin >> inputS)
    {
        count++;
    }

    cout << count;

}

void Sangsu()
{
    char num1[5];
    char num2[5];

    cin >> num1;
    cin >> num2;

    int jari = 1;
    int temp1 = 0;
    for(int i = 0; i < strlen(num1); i++)
    {
        temp1 += (num1[i] - '0') * jari;
        jari *= 10;
    }

    jari = 1;
    int temp2 = 0;
    for (int i = 0; i < strlen(num2); i++)
    {
        temp2 += (num2[i] - '0') * jari;
        jari *= 10;
    }
    
    int ans = temp2;
    temp1 > temp2? ans = temp1: 0;

    cout << ans;
    
    //int num2Count = strlen(num2);
    // sizeof: ���� �����ϰ� �ִ� �޸�
    // strlen: ���ڿ��� ���̸� ���Ѵ�. �� �� ���̴� NULL ���ڸ� ���� �������� ���ڼ��� ����.
}

void Dial()
{
    int arr[26] = { 3,3,3,
                    4,4,4,
                    5,5,5,
                    6,6,6,
                    7,7,7,
                    8,8,8,8,
                    9,9,9,
                    10,10,10,10};

    
    string inputS;
    cin >> inputS;

    int ans = 0;
    for(int i = 0; i < inputS.size(); i++)
    {
        int temp = inputS[i] - 'A';
        ans += arr[temp];
    }

    cout << ans;
}

void CroatiaABC()
{
    string wordList[8] = {"c=", "c-",
                           "dz=", "d-",
                           "lj", "nj",
                           "s=", "z="};

    string inputString;
    cin >> inputString;

    string temp = "";
    int sum = 0;
    int sumWordCount = 0;

    // inputString ó������ ������ ����
    for(int i = 0; i < inputString.size() - 1; i++)
    {
        // wordlist [0] ~ [8] ���� �ݺ�
        for(int j = 0; j < 8; j++)
        {
            temp = "";
            int wordCount = wordList[j].size();

            if(i + wordCount > inputString.size()) continue;

            for(int k = 0; k < wordCount; k++)
            {
                temp += inputString[i+k];
            }

            if(temp == wordList[j])
            {
                sum++;
                sumWordCount += wordCount;
                i += (wordCount - 1);
            }
        }
    }

    int nokori = inputString.size() - sumWordCount;
    sum += nokori;

    cout << sum << endl;
}


void GroupWordCheck()
{
    int lineCount = 0;
    int abc[26] = {0,};
    int ans = 0;
    string inputStringArr[100];

    cin >> lineCount;
    
    for(int i = 0; i < lineCount; i++)
    {
        cin >> inputStringArr[i];
    }

    bool chk = false;
    for(int k = 0; k < lineCount; k++)
    {
        chk = true;

        for(int i = 0; i < inputStringArr[k].size() - 1; i++)
        {
            // ���� ���� �ٸ� ��츸 ó��. �׷��� if�� 2���� ó�� ����.
            if(inputStringArr[k][i] != inputStringArr[k][i+1])
            {
                abc[inputStringArr[k][i] - 'a'] = 1;

                // �ٸ���, ���ڸ��� �ִ� ���� �̹� �۵��ƴ� ���̴�? �׷� X
                if(abc[inputStringArr[k][i+1] - 'a'] > 0)
                {
                    chk = false;
                    break;
                }
            }
        }

        for(int m = 0; m < 26; m++) abc[m] = 0;

        if (chk) ans++;
    }

    cout << ans;
}

void BreakEvenPoint()
{
    /*
    �������ڴ� ��Ʈ���� �����ϰ� �Ǹ��ϴ� ȸ���̴�. ��Ʈ�� �Ǹ� ����� ������� �ų� �Ӵ��, ��꼼, �����, �޿� �� 
    A������ ���� ����� ���, �� ���� ��Ʈ���� �����ϴ� ������ ����� �ΰǺ� �� �� B������ ���� ����� ��ٰ� �Ѵ�.
    
    ���� ��� A=1,000, B=70�̶�� ����. �� ��� ��Ʈ���� �� �� �����ϴ� ���� �� 1,070������ ���, �� �� �����ϴ� ���� �� 1,700������ ���.
    
    ��Ʈ�� ������ C�������� å���Ǿ��ٰ� �Ѵ�. �Ϲ������� ���� ����� �÷� ���� ���� ��� ���� �� ����(�Ǹź��)�� �� ���(=�������+�������)���� �������� �ȴ�. 
    ���ʷ� �� ������ �� ��뺸�� ������ ������ �߻��ϴ� ������ ���ͺб���(BREAK-EVEN POINT)�̶�� �Ѵ�.
    
    A, B, C�� �־����� ��, ���ͺб����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
    

    A: ���� ���
    B: ���� ���
    C: ��Ʈ�� ����

    �Է�
    ù° �ٿ� A, B, C�� �� ĭ�� ���̿� �ΰ� ������� �־�����. A, B, C�� 21�� ������ �ڿ����̴�.
    
    ���
    ù ��° �ٿ� ���ͺб��� �� ���ʷ� ������ �߻��ϴ� �Ǹŷ��� ����Ѵ�. ���ͺб����� �������� ������ -1�� ����Ѵ�.
    
    ���� �Է� 1         ���� ��� 1 
    1000 70 170          11
    
    ���� �Է� 2         ���� ��� 2
    3 2 1               -1
     
    ���� �Է� 3         ���� ��� 3
    210 000 000 0 9 10     210 000 000 1
    */

    long long a;          // �������
    long long b;          // �������
    long long c;          // ���԰���

    cin >> a >> b >> c;
    int cnt = 0;
    
    if(b > c) cnt = 0;
    else cnt = (a / (c - b)) + 1;

    cout << cnt;
}

void FindHide()
{
    int hide = 1;
    int cnt = 1;
    int sum = 0;
    int n = 0;

    cin >> n;

    while(n >= hide)
    {
        sum += 6;
        hide += sum;
        cnt++;
    }

    cout << cnt;
}

void BunsuFind()
{
    int N = 0;          // ã�� ��ȣ
    int cnt = 0;        // �� ��° �밢���ΰ�?
    int sumCnt = 0;     // ���� ���� ����

    cin >> N;
    while(true)
    {
        cnt++;
        sumCnt += cnt;
        
        if(sumCnt >= N) break;
    }
    int top = 0;
    int bottom = 0;
    if(cnt % 2 == 1)                // Ȧ���� ��
    {
        top = sumCnt - N + 1;
        bottom = cnt + 1 - top;
    }
    else                            // ¦���� ��
    {
        bottom = sumCnt - N + 1;
        top = cnt + 1 - bottom;
    }

    cout << top << "/" << bottom;
}

void SnailUp()
{
    int a;
    int b;
    int v;
    int cnt = 0;

    cin >> a;
    cin >> b;
    cin >> v;

    cnt = (v-b) / (a-b);

    if((v-b) % (a-b)) cnt++;

    cout << cnt;
}

void ACMHotel()
{
    int t;
    int h, w, n;
    int ans;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;

        if(n % h == 0) ans = h * 100 + (n / h);
        else ans = (n % h) * 100 + (n / h) + 1;

        cout << ans << endl;
    }

}

void BeDonePresident()
{
    int testCase = 0;
    int floor = 0;
    int num = 0;
    int arr[15][15] = {0,};

    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        cin >> floor >> num;

        for(int i = 0; i <= floor; i++)
        {
            arr[i][1] = 1;
        }

        int cnt = 1;
        for(int i = 1; i <= num; i++)
        {
            arr[0][i] = cnt;
            cnt++;
        }

        // floor
        for(int f = 1; f <= floor; f++)
        {
            // num
            for(int n = 2; n <= num; n++)
            {
                arr[f][n] = arr[f][n-1] + arr[f-1][n];
            }
        }

        cout << arr[floor][num] << endl;
    }
}

void SugarDelivery()
{
    int cnt = 0;
    int N = 0;

    cin >> N;
    
    if(!(N%5)) 
    {
        cout << N/5;
        return;
    }
    
    while( N > 0)
    {
        N -= 3;
        cnt++;

        if(!(N%5)) 
        {
            cnt += N/5;
            break;
        }
    }

    if(N < 0) cout << -1;
    else cout << cnt;
}

void SumBigNum()
{
    string a;
    string b;
    string ans;

    cin >> a >> b;

    int chai = a.size() - b.size();
    chai = abs(chai);

    int strSize = a.size();
    if(strSize < b.size()) strSize = b.size();

    for(int i = 0; i < chai; i++)
    {
        if(a.size() < b.size()) a.insert(0, "0");
        else b.insert(0,"0");
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    for(int i = 0; i < strSize; i++)
    {
        a[i];
        int aa = a[i] - '0';
        int bb = b[i]  - '0';
        int temp = aa + bb + carry;

        if(temp > 9)
        {
            carry = 1;
            temp -= 10;
        }
        else carry = 0;

        ans += (temp + '0');
    }

    if(carry) ans += '1';

    reverse(ans.begin(), ans.end());

    cout << ans;
}

void FindSosu()
{
    int N;
    cin >> N;
    
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int inputNum;
        cin >> inputNum;

        if(inputNum == 1) continue;

        bool ChkSosu = true;
        for(int j = 2; j < inputNum; j++)
        {
            if(inputNum % j) ChkSosu = true;
            else
            {
                ChkSosu = false;
                break;
            }
        }

        if(ChkSosu) ans++;
    }

    cout << ans;
}

void Sosu()
{
    int M;
    cin >> M;

    int N;
    cin >> N;

    int sum = 0;
    int min = 11111;
    for (int i = M; i <= N; i++)
    {
        if (i == 1) continue;

        bool ChkSosu = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j) ChkSosu = true;
            else
            {
                ChkSosu = false;
                break;
            }
        }

        if (ChkSosu)
        {
            sum += i;

            if(i < min) min = i;
        }
    }

    if(!sum) cout << -1;
    else
    {
        cout << sum << endl;
        cout << min;
    }
}

void SoinsuBunhae()
{
    int N;
    cin >> N;

    vector<int> ans;
    while(N > 1)
    {
        for(int i = 2; i <= N; i++)
        {
            if(N % i == 0)
            {
                N = (N/i);
                ans.push_back(i);
                break;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(int i : ans)
        cout << i << endl;
}

void Sosu2()
{
    int M;
    int N;
    int sqrtNum;

    cin >> M >> N;

    if (M == 1) M++;
    if (M == 2 && M <= N)
    {
        cout << 2 << endl;
        M++;
    }
    if (M == 3 && M <= N)
    {
        cout << 3 << endl;
        M++;
    }

    for (int i = M; i <= N; i++)
    {
        if(i % 2 == 0) continue;
        sqrtNum = sqrt(i);

        for (int j = 2; j <= sqrtNum; j++)
        {
            if(!(i % j)) break;    

            if (j == sqrtNum) cout << i << '\n';
        }
    }
}

void Sosu2_2()
{
    int M;
    int N;

    cin >> M >> N;

    vector<bool> arr(N+1, false);

    // Create
    for(int i = 2; i <= N; i++)
    {
        arr[i] = true;
    }


    //int sqrtNum = sqrt(N);
    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j <= N; j += i)
        {
            arr[j] = 0;
        }
    }

    // cout
    for(int i = M; i <= N; i++)   
    {
        if(arr[i]) cout << i << '\n';
    }
}

void BertGonjun()
{
    int M;
    int N = 1;

    while(true)
    {
        int M;
        cin >> M;

        if(!M) break;

        N = M * 2;

        vector<bool> arr((M * 2) + 1, false);

        int cnt = 0;

        // Create
        for (int i = 2; i <= N; i++)
        {
            arr[i] = true;
        }


        //int sqrtNum = sqrt(N);
        for (int i = 2; i * i <= N; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
            for (int j = i + i; j <= N; j += i)
            {
                arr[j] = 0;
            }
        }

        // cout
        for (int i = M + 1; i <= N; i++)
        {
            if (arr[i]) cnt++;
        }

        cout << cnt << endl;
    }
}

void GoldBath()
{
    int testCase;
    int N;
    cin >> testCase;

    bool arr[10001];

    // 1. ä�� 2 ~ 10,000 ���� �Ҽ��� �ɷ�����
    // if(i ==  �Ҽ�)
    // 2. 2���� �����ؼ� 2 + (�ڽ� + n-a)���� �ݺ��Ѵ�.
    //           if( �� ���� > n) break;
    // 3. 3... 4.... �����Ѵ�. 

    // 1. ä �����
        // �迭 �ʱ�ȭ
    for (int i = 2; i <= 10000; i++)
    {
        arr[i] = 1;
    }
    

    for (int i = 2; i * i <= 10000; i++)
    {
        if (arr[i] == 0) continue;

        for (int j = i + i; j <= 10000; j += i)
        {
            arr[j] = 0;
        }
    }

    // �˰��� ����
    for(int t = 0; t < testCase; t++)
    {
        cin >> N;

        int ansA = 0;
        int ansB = 0;
        for(int i = N * 0.5; i >= 2; i--)
        {
            if(arr[i] == 0) continue;

            for(int j = N * 0.5; j < N; j++)
            {
                if(arr[j] == 0) continue;

                if(i + j == N) 
                {
                    ansA = i;
                    ansB = j;
                    break;
                }
            }
            if(ansA > 0) break;
        }

        cout << ansA << " " << ansB << "\n";
    }

}

int Factorial(int N)
{
    if(N <= 1) return 1;
    return N * Factorial(N-1);

    /*
    int n = 0;
    cin >> n;
    n = Factorial(n);
    cout << n;*/
}

int Pibonachi(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;

    return Pibonachi(N-1) + Pibonachi(N-2);
}



int WhatIsRecursiveFunction(int N)
{
    // �ٽ� ����� ���� ���������� ������ ��
    static int cnt = 0;
    static string str = "";

    if(N == 0)
    {
        printf("%s\"����Լ��� ������?\"\n", str.c_str());
        printf("%s\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", str.c_str());
        
        for(int i = 0; i <= cnt; i++)
        {
            printf("%s��� �亯�Ͽ���.\n", str.c_str());
            str.erase(0,4);
        }
        return 0;
    }

    {
        printf("%s\"����Լ��� ������?\"\n", str.c_str());
        printf("%s\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", str.c_str());
        printf("%s���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", str.c_str());
        printf("%s���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", str.c_str());
        
        str += "____";
        cnt++;
        return WhatIsRecursiveFunction(--N);
    }

    /*
    int main()
    {
        int n;
        cin >> n;

        printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");

        WhatIsRecursiveFunction(n);
    }
    */

}


void StarRecursiveFunction(int i, int j, int n)
{
        if (i / n % 3 == 1 && j / n % 3 == 1)
        {
            cout << " ";
        }
        else if (n / 3 == 0) {
            cout << "*";
        }
        else {
            StarRecursiveFunction(i, j, n / 3);
        }
        /*
        int main()
        {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    StarRecursiveFunction(i, j, n);
                }
                cout << '\n';
            }
        }
        */
}


//        ���ǰ���,         �����,   ������,   ������
// N���� ������, startPoint���� defstnation���� �̵��ϴµ�, ������ reference�� ����ϰڴ�.
void hanoi(int N, int startPoint, int destnation, int reference)
{
    // �̵��� ������ ���� 1�����?
    if(N == 1)
    {
        cout << startPoint << ' ' << destnation << '\n';
        return;
    }
    else
    {
        // A -> C�� �ű�ٰ� ����
        // Step 1: N-1���� A���� B�� �̵� (= start ������ N-1���� ������ ������(def) �������� �̵�)
        hanoi(N - 1, startPoint, reference, destnation);
        
        // Step 2: 1���� A���� C�� �̵�    (= start ������ N��° ������ ������(def) �������� �ű��)
        cout << startPoint << ' ' << destnation << '\n';

        // Step 3: N-1���� B���� C�� �̵� (= ������(ref) ������ N-1���� ������ ������(def) �������� �ű��
        hanoi(N - 1, reference, destnation, startPoint);
    }
    /*
    int main()
    {
        int n;
        cin >> n;
    
        cout << (int)pow(2,n) -1 << '\n';
        hanoi(n, 1, 3, 2);
    
        return 0;
    }
    
    */
}

void Blackjack()
{
    int N;
    int M;

    cin >> N >> M;

    vector<int> vNum;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        vNum.push_back(temp);
    }

    sort(vNum.begin(), vNum.end(), greater<int>());

    // ���� ū �� + �� �������� ū ��

    // 2��°
    int nowNum = 0;
    int maxNum = 0;
    for(int k = 0; k < vNum.size() - 2; k++)
    {
        for(int i = k + 1; i < vNum.size() - 1; i++)
        {
            nowNum = vNum[k] + vNum[i];

            if(nowNum >= M) continue;

            // ������ �� ���ϴ� ��
            for(int j = i + 1; j < vNum.size(); j++)
            {
                nowNum += vNum[j];

                if(nowNum == M) 

                {
                    cout << nowNum;
                    return;
                }
                else if( maxNum < nowNum && nowNum < M)
                {
                    maxNum = nowNum;
                }

                nowNum -= vNum[j];
            }
        }
    }

    cout << maxNum;
}

void BunhaeHab()
{
    int quest;
    cin >> quest;

    for(int i = 1; i < quest; i++)
    {
        string temp;
        temp = to_string(i);

        int itemp = i;
        for(char a : temp)
        {
            itemp += (a - '0');
        }

        if(itemp == quest)
        {
            cout << i;
            return;
        }
    }
    //1. ���� �ϳ� �޴´�
    //2. ���� ���� �������� ���Ѵ�.
    //3. ����Ѵ�.

    cout << 0;
}

void Dungchi()
{
    vector<pair<int, int>> a;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        int y;

        cin >> x >> y;

        a.push_back(make_pair(x,y));
    }

    for(int i = 0; i < n; i++)
    {
        int grade = 1;

        for(int j = 0; j < n; j++)
        {
            if( i == j ) continue;

            if(a[i].first < a[j].first && a[i].second < a[j].second) 
                grade++;

        }

        cout << grade;

        if(i < (n-1)) cout << ' ';
    }
}

void ChessPhan()
{
    int n, m;
    int cnt = 0;
    char c, nc;
    cin >> n;
    cin >> m;

    string s;
    cin >> s;
    cout << s;
    //for(int i = 0; i < n; i++)
    //{
    //    for(int j = 0; j < m-1; j++)
    //    {
    //        char c;
    //        cin >> c;

    //        
    //    }
    //}

    cout << cnt;
}

void Wizang()
{
    vector<vector<string>> clothes = { {"yellow_hat","headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    map<string, int> map;

    int answer = 1;

    for (auto i : clothes)
        map[i[1]]++;

    for (auto i : map)
        answer *= i.second;

    cout << answer << endl;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
} //��������

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
} //��������

vector<int> BestAlbum()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    map<string, int> genresSum;               // �� �帣 : �÷��̼�
    map<string, vector<int>> genresUniqueNum; // �� �帣 : ������ȣ

    vector<int> answer;
    map<string, int> sumGenresPlays;          // �帣 : ���÷��̼�
    map<string, vector<pair<int, int>>> map2; // �帣 : vector<������ȣ, �����>

    // 1. �帣 : �÷�������
    for (int i = 0; i < genres.size(); i++)
    {
        sumGenresPlays[genres[i]] += plays[i];    // �帣 : �÷�������
        map2[genres[i]].push_back({ i, plays[i] }); // �帣 : vector<������ȣ, �����>
    }

    // 2. �帣: �÷������� ���Ϳ� �Űܼ� �������� ����
    vector<pair<string, int>> vGenresPlaySum(sumGenresPlays.begin(), sumGenresPlays.end());

    // 2-1) �帣 : �÷������� ����
    sort(vGenresPlaySum.begin(), vGenresPlaySum.end(), cmp);

    // 2-2) �帣 : vector<������ȣ, �����>, ����� ���� ����
    for (auto& i : map2)
    {
        sort(i.second.begin(), i.second.end(), cmp2);
    }

    // 3. �帣�� ��������� ��������, vGenresPlaySum�� �帣(first)�� �޾Ƽ�
    //    map2[�帣]�� ����[0], [1]�� answer�� �־��ش�.
    for (auto i : vGenresPlaySum)
    {
        if (map2[i.first].size() < 2)
            answer.push_back(map2[i.first][0].first);
        else
        {
            answer.push_back(map2[i.first][0].first);
            answer.push_back(map2[i.first][1].first);
        }
    }

    for (auto i : answer)
        cout << i << endl;

    return answer;
}

void FunctionDevelope()
{
    vector<int> progresses({ 93, 30, 55 });
    vector<int> speeds({ 1, 30, 5 });
    vector<int> answer;
    queue<int> q;

    // 100 - ���α׷���.size()
    // q�� 
    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] == 0) {
            q.push((100 - progresses[i]) / speeds[i]);
        }
        else {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }

    // q�� ������� ������ �ݺ�
    while (!q.empty()) {
        int cnt = 1;                // cnt = 1
        int current = q.front();    // ����: q�� �Ǿ�
        q.pop();                    // q �� �� ����ְ�

        // q�� ������� �ʰ�, q�� front�� ���簪���� �۴ٸ�
        while (!q.empty() && q.front() <= current) {
            cnt++;      // cnt++
            q.pop();    // q �տ� ����ְ�
        }
        answer.push_back(cnt);
    }
}

void FunctionDevelopeDay2()
{
    vector<int> progresses({ 93, 30, 55 });
    vector<int> speeds({ 1, 30, 5 });
    vector<int> answer;
    vector<int> q;
    int cnt = 0;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)
        {
            q.push_back((100 - progresses[i]) / speeds[i]);
        }
        else
            q.push_back((100 - progresses[i]) / speeds[i] + 1);
    }

    int cntNum = 1;
    int curNum;
    while (!q.empty())
    {
        cntNum = 1;
        curNum = q[0];
        q.erase(q.begin());

        while (!q.empty() && q[0] <= curNum)
        {
            cntNum++;
            q.erase(q.begin());
        }

        answer.push_back(cntNum);
    }
}

class A
{
public:
    A(){}
    virtual void Update() { cout << "AUpdate()" << endl;}  
};

class B : public A
{
public:
    B() {}
    void Update() { cout << "BUpdate()" << endl; }
};

class C : public B
{
public:
    C() {}
    void Update() { cout << "CUpdate()" << endl; }
};

int SearchBinary(int item, vector<int> list)
{
    int low = 0;
    int high = list.size()-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int guess = list[mid];

        if(guess == item) return mid;

        if(item > guess) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;

    /*
    int main()
    {
      vector<int> myList{1, 3, 5, 7, 9}; 
      cout << SearchBinary(1, myList);
    }
    */
}

int lowNumInArr(vector<int> arr)
{
    int index = 0;
    int lowNum = INT_MAX;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < lowNum)
        {
            lowNum = arr[i];
            index = i;
        }
    }

    return index;
}

void selectionSort()
{
    vector<int> a{5, 3, 6, 2, 10};
    vector<int> answer;

    int size = a.size();

    for (size_t i = 0; i < size; i++)
    {
        int index = lowNumInArr(a);
        answer.push_back(a[index]);
        a.erase(a.begin() + index);
    }

    
    for(auto i : answer)
        cout << i << " ";
}
vector<int> quickSort(vector<int> inputVector)
{
    if(inputVector.size() < 2) return inputVector;

    int pivot = inputVector[0];
    
    vector<int> lessVector;
    vector<int> greaterVector;

    for(int i = 1; i < inputVector.size(); i++)
    {
        if(inputVector[i] < pivot)
        {
            lessVector.push_back(inputVector[i]);
        }
        else
        {
            greaterVector.push_back(inputVector[i]);
        }
    }

    vector<int> totalLessVector = quickSort(lessVector);
    vector<int> totalGreaterVector = quickSort(greaterVector);

    vector<int> total(totalLessVector);
    total.push_back(pivot);
    
    for(auto i : totalGreaterVector)
        total.push_back(i);

    return total;

    /*
    int main()
    {
        vector<int> temp{11,9,24,3,5,6,7,8};

        vector<int> i = quickSort(temp);

        for(auto k : i)  cout << k << " ";
    }
    */
}

string SearchDragUser()
{
    map<string, vector<string>> graph;
    graph["you"] = {"alice", "bob", "Clare"};
    graph["bob"] = {"anju", "pegy"};
    graph["alice"] = {"pegy"};
    graph["Clare"] = {"tom", "jony"};
    graph["anju"];
    graph["pegy"];
    graph["tom"];
    graph["jony"];

    queue<string> q;

    for (auto& i : graph["you"])
    {
        q.push(i);
    }

    while (q.size())    // q ���� ������ �ݺ�
    {
        // ������̸� ����
        if (q.front().back() == 'm')
        {
            cout << "����: " << q.front() << endl;
            return q.front();
        }

        else // ����� �ƴ϶�� ť�� ������� �߰�
        {
            for (auto& i : graph[q.front()])
            {
                q.push(i);
            }

            q.pop();
        }
    }
    
    //printf(" ");
}

//���ͽ�Ʈ��
void graphInit(map<string, map<string, int>>& _graph)
{
    _graph["strat"]["a"] = 6;
    _graph["strat"]["b"] = 2;

    _graph["a"]["fin"] = 1;
    
    _graph["b"]["a"] = 3;
    _graph["b"]["fin"] = 5;
    
    _graph["fin"];
}

void costInit(map<string, int>& _cost)
{
    _cost["a"] = 6;
    _cost["b"] = 2;
    _cost["fin"] = INT_MAX;
}

void parentsInit(map<string, string>& _parents)
{
    _parents["a"] = "start";
    _parents["b"] = "start";
    _parents["fin"] = "";

}

// �ڽ�Ʈ�� ���� ��� ã��
string FindLowCostNode(map<string, int> costs, map<string, bool> _processed)
{
    int lowCost = INT_MAX;
    string lowCostNode = "";
    
    for (auto node : costs)             // ���ǥ
    {
        int cost = costs[node.first];   // for: ���� ����� ���

        // ���ǥ���� ���� ���� �ڽ�Ʈ ��� ã��
        if (cost < lowCost && (_processed[node.first] == false))
        {
            lowCost = cost;
            lowCostNode = node.first;
        }
    }

    return lowCostNode;
}

void djstra()
{
    map<string, int>              costs;
    map<string, string>           parents;

    map<string, map<string, int>> graph;
    map<string, bool> processed;

    // �׷���, �ڽ�Ʈ, �θ�ǥ ����
    graphInit(graph); 
    costInit(costs);
    parentsInit(parents);

    string node = FindLowCostNode(costs, processed);
    while (node.size() > 0)
    {
        int cost = costs[node];         // ���� ����� ���
        auto edgeNodes = graph[node];   // ���� ���� �̾��� ���:���

        for (auto n : edgeNodes)
        {
            int newCost = cost + edgeNodes[n.first];    // ex) ��ŸƮ->B �ڽ�Ʈ: 2,
                                                        //         B->A   cost: 3, 2+3 = 5
            if (costs[n.first] > newCost)               //     ��ŸƮ->A ���> (B���� �ڽ�Ʈ + B->A ���)
            {
                costs[n.first] = newCost;
                parents[n.first] = node;
            }
        }
        
        processed[node] = true;
        node = FindLowCostNode(costs, processed);
    }

    for (auto i : costs) cout << i.first << ": " << i.second << endl;;
    for (auto i : parents) cout << i.first << ": " << i.second << endl;
}

// �ٻ� �˰���
void ApproximationAlgorithm()
{/*
     Err: ���� ���� �߸���
        - set_intersection
     set_interction ����
        - ����: output Vector�� resize�� ���� "" �׿��� ����
        - �ذ�: interction�� �� std::back_inserter(vector3)
        - ����: Return value
                A std::back_insert_iterator which can be used to add elements to the end of the container c
     �ذ�Ǵ� ���� ã��
          - backInserter�� ��� �ڿ��� �ѵΰ� �� ���Ұ� ���� �ذ�Ǵ� ������ ����.

          - kone �� begin()�� ���, "" �� 8 > 7
          -         back_inserter, "" �� 8 > 9, 
  */              
    vector<string> states_needed{ "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
    map<string, vector<string>> stations;
    stations["kone"] = {"id", "nv", "ut"};
    stations["ktwo"] = {"wa", "ia", "mt"};
    stations["kthree"] = {"or","nv","ca"};
    stations["kfour"] = {"nv", "ut"};
    stations["kfive"] = {"ca", "az"};

    vector<string> final_stations;

    // ���� Ŀ���ľ� �� ������
    while (states_needed.size() > 0)
    {
        string bestStation;
        vector<string> states_covered; // Ŀ���� ����

        // Ŀ���ľ� �� ������ ����
        for (auto& station : stations)
        {                
            // covered: ���� ���� �� ��۱��� ó�������� ����
            sort(states_needed.begin(), states_needed.end());
            sort(station.second.begin(), station.second.end());
            vector<string> covered;
            
            set_intersection(states_needed.begin(), states_needed.end(),
                            station.second.begin(), station.second.end(),
                            std::back_inserter(covered));

            // ó������ ���� > ��۱� ó������
            // �� ��۱��� ������ bestStation���� �� ���� �ָ� Ŀ���ϴ°�?
            if (covered.size() > states_covered.size())
            {
                bestStation = station.first;
                states_covered = covered;
            }
        }
        
        // ���� �������� Ŀ���� ������ ����(�����ʿ�) && ��۱� ����
        for (auto i : states_covered)
            states_needed.erase(std::remove(states_needed.begin(), states_needed.end(), i), states_needed.end());

        // states_needed -= states_covered;
        final_stations.push_back(bestStation);
    }

    for (auto i : final_stations)
        cout << i << endl;
}

int main()
{
    ApproximationAlgorithm();
}

/* map ����, #map #map<map> #map<int>

    map<string, vector<pair<string, int>>> a;
    a["start"].push_back({ "A", 1 });
    a["start"].push_back({ "B", 2 });

    cout << a["start"][0].first << " " << a["start"][0].second << endl;
    cout << a["start"][1].first << " " << a["start"][1].second << endl;

    map<string, map<string, int>> mb;
    mb["string"]["a"] = 6;
    mb["string"]["b"] = 8;
    mb["string"].insert({ "c", 9 });

    cout << "a: " << mb["string"]["a"] << endl;
    cout << "b: " << mb["string"]["b"] << endl;

    // ��� 1) mb["string"]["a"] = 6;
    // ��� 2) mb["string"].insert({"c", 9});

    vector
        vector �ߺ�����
            vector<string> temp;
            temp.erase(unique(temp.begin(), temp.end()), temp.end())
*/