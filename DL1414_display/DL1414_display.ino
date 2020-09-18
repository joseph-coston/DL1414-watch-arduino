#include <Arduino.h>

/* DL1414 character set definitions:
 * Each character is defined as an 8 char long string of 1s and 0s that is NULL
 * terminated. Each char in the string stands for the state of an input pin on
 * the DL1414 chip and holds a binary value of either TRUE or FALSE. The
 * leftmost char in the string represents the state of pin D6 on the DL1414 and
 * the rightmost char represents the state of D0.
 */
/* SPECIAL CHARACTERS */
const int Spc[] = {0,1,0,0,0,0,0}; /* [ ] white space (blank) */
const int Exp[] = {0,1,0,0,0,0,1}; /* [!] exclamation point */
const int Ats[] = {1,0,0,0,0,0,0}; /* [@] at sign */
const int Pnd[] = {0,1,0,0,0,1,1}; /* [#] pound sign */
const int Dlr[] = {0,1,0,0,1,0,0}; /* [$] dollar sign */
const int Mod[] = {0,1,0,0,1,0,1}; /* [%] percent sign */
const int Xor[] = {1,0,1,1,1,1,0}; /* [^] carrot */
const int And[] = {0,1,0,0,1,1,0}; /* [&] ampersand */
const int Ast[] = {0,1,0,1,0,1,0}; /* [*] asterisk (multiplication) */
const int Opr[] = {0,1,0,1,0,0,0}; /* [(] open parentheses */
const int Cpr[] = {0,1,0,1,0,0,1}; /* [)] closed parentheses */
const int Mns[] = {0,1,0,1,1,0,1}; /* [-] minus sign (dash/hyphen) */
const int Uln[] = {1,0,1,1,1,1,1}; /* [_] underscore */
const int Pls[] = {0,1,0,1,0,1,1}; /* [+] plus sign */
const int Eql[] = {0,1,1,1,1,0,1}; /* [=] equals sign */
const int Obr[] = {1,0,1,1,0,1,1}; /* [[] open bracket */
const int Cbr[] = {1,0,1,1,1,0,1}; /* []] closed bracket */
const int Bsh[] = {1,0,1,1,1,0,0}; /* [\] back slash  */
const int Sem[] = {0,1,1,1,0,1,1}; /* [;] semicolon */
const int Col[] = {0,1,1,1,0,1,0}; /* [:] colon */
const int Apt[] = {0,1,0,0,1,1,1}; /* ['] apostrophe */
const int Qtm[] = {0,1,0,0,0,1,0}; /* ["] quotation mark */
const int Com[] = {0,1,0,1,1,0,0}; /* [,] comma */
const int Lth[] = {0,1,1,1,1,0,0}; /* [<] less-than sign */
const int Prd[] = {0,1,0,1,1,1,0}; /* [.] period (decimal) */
const int Gth[] = {0,1,1,1,1,1,0}; /* [>] greater-than sign */
const int Fsh[] = {0,1,0,1,1,1,1}; /* [/] forward slash (division) */
const int Qst[] = {0,1,1,1,1,1,1}; /* [?] question mark */

/* NUMBERS */
const int No0[] = {0,1,1,0,0,0,0}; /* [0] zero */
const int No1[] = {0,1,1,0,0,0,1}; /* [1] one */
const int No2[] = {0,1,1,0,0,1,0}; /* [2] two */
const int No3[] = {0,1,1,0,0,1,1}; /* [3] three */
const int No4[] = {0,1,1,0,1,0,0}; /* [4] four */
const int No5[] = {0,1,1,0,1,0,1}; /* [5] five */
const int No6[] = {0,1,1,0,1,1,0}; /* [6] six */
const int No7[] = {0,1,1,0,1,1,1}; /* [7] seven */
const int No8[] = {0,1,1,1,0,0,0}; /* [8] eight */
const int No9[] = {0,1,1,1,0,0,1}; /* [9] nine */

/* LETTERS */
const int _A_[] = {1,0,0,0,0,0,1}; /* [A] capital a */
const int _B_[] = {1,0,0,0,0,1,0}; /* [B] capital b */
const int _C_[] = {1,0,0,0,0,1,1}; /* [C] capital c */
const int _D_[] = {1,0,0,0,1,0,0}; /* [D] capital d */
const int _E_[] = {1,0,0,0,1,0,1}; /* [E] capital e */
const int _F_[] = {1,0,0,0,1,1,0}; /* [F] capital f */
const int _G_[] = {1,0,0,0,1,1,1}; /* [G] capital g */
const int _H_[] = {1,0,0,1,0,0,0}; /* [H] capital h */
const int _I_[] = {1,0,0,1,0,0,1}; /* [I] capital i */
const int _J_[] = {1,0,0,1,0,1,0}; /* [J] capital j */
const int _K_[] = {1,0,0,1,0,1,1}; /* [K] capital k */
const int _L_[] = {1,0,0,1,1,0,0}; /* [L] capital l */
const int _M_[] = {1,0,0,1,1,0,1}; /* [M] capital m */
const int _N_[] = {1,0,0,1,1,1,0}; /* [N] capital n */
const int _O_[] = {1,0,0,1,1,1,1}; /* [O] capital o */
const int _P_[] = {1,0,1,0,0,0,0}; /* [P] capital p */
const int _Q_[] = {1,0,1,0,0,0,1}; /* [Q] capital q */
const int _R_[] = {1,0,1,0,0,1,0}; /* [R] capital r */
const int _S_[] = {1,0,1,0,0,1,1}; /* [S] capital s */
const int _T_[] = {1,0,1,0,1,0,0}; /* [T] capital t */
const int _U_[] = {1,0,1,0,1,0,1}; /* [U] capital u */
const int _V_[] = {1,0,1,0,1,1,0}; /* [V] capital v */
const int _W_[] = {1,0,1,0,1,1,1}; /* [W] capital w */
const int _X_[] = {1,0,1,1,0,0,0}; /* [X] capital x */
const int _Y_[] = {1,0,1,1,0,0,1}; /* [Y] capital y */
const int _Z_[] = {1,0,1,1,0,1,0}; /* [Z] capital z */

/* digital I/O pins corresponding to each character select pin */
#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
const int D[] = {8,7,6,5,4,3,2}; /* notice array order is reverse of above */

/* cursor pins - 00 for left, 11 for right*/
#define A1 10
#define A2 11

/* write pins - 1 preserves last state, 0 stores current state */
#define WRR 9   /* right display */
#define WRL 12  /* left display */

/* uses digitalWrite to set the character pins to the values in the passed array*/
void setChPins(const int *character) 
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(D[i], character[i]);
  }
  return;
}

/* puts character c on the display at index n - LtR indexing begining at 0 */
void hpdlPutC(char c, int n) 
{
  /* set proper cursor pins */
  switch (n % 4) { /* 4 is the number of indexes per display */
    case 0:
      digitalWrite(A1, 1); /* leftmost index */
      digitalWrite(A2, 1); 
      break;
    case 1:
      digitalWrite(A1, 1);
      digitalWrite(A2, 0); 
      break;
    case 2:
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      break;
    case 3:
      digitalWrite(A1, 0); /* rightmost index */
      digitalWrite(A2, 0);
      break;
  }
  
  switch (c) { /* set the proper the character pins */
    /* alphebet */
    case 'a':
    case 'A':
      setChPins(_A_);
      break;
    case 'b':
    case 'B':
      setChPins(_B_);
      break;
    case 'c':
    case 'C':
      setChPins(_C_);
      break;
    case 'd':
    case 'D':
      setChPins(_D_);
      break;  
    case 'e':
    case 'E':
      setChPins(_E_);
      break;
    case 'f':
    case 'F':
      setChPins(_F_);
      break;
    case 'g':
    case 'G':
      setChPins(_G_);
      break;
    case 'h':
    case 'H':
      setChPins(_H_);
      break;
    case 'i':
    case 'I':
      setChPins(_I_);
      break;  
    case 'j':
    case 'J':
      setChPins(_J_);
      break;  
    case 'k':
    case 'K':
      setChPins(_K_);
      break;
    case 'l':
    case 'L':
      setChPins(_L_);
      break;
    case 'm':
    case 'M':
      setChPins(_M_);
      break;
    case 'n':
    case 'N':
      setChPins(_N_);
      break;  
    case 'o':
    case 'O':
      setChPins(_O_);
      break;  
    case 'p':
    case 'P':
      setChPins(_P_);
      break;
    case 'q':
    case 'Q':
      setChPins(_Q_);
      break;
    case 'r':
    case 'R':
      setChPins(_R_);
      break;
    case 's':
    case 'S':
      setChPins(_S_);
      break;  
    case 't':
    case 'T':
      setChPins(_T_);
      break;  
    case 'u':
    case 'U':
      setChPins(_U_);
      break;
    case 'v':
    case 'V':
      setChPins(_V_);
      break;
    case 'w':
    case 'W':
      setChPins(_W_);
      break;
    case 'x':
    case 'X':
      setChPins(_X_);
      break;  
    case 'y':
    case 'Y':
      setChPins(_Y_);
      break; 
    case 'z':
    case 'Z':
      setChPins(_Z_);
      break;
      
    /* numbers */
    case '0':
      setChPins(No0);
      break;
    case '1':
      setChPins(No1);
      break;
    case '2':
      setChPins(No2);
      break;
    case '3':
      setChPins(No3);
      break;  
    case '4':
      setChPins(No4);
      break;
    case '5':
      setChPins(No5);
      break;
    case '6':
      setChPins(No6);
      break;
    case '7':
      setChPins(No7);
      break;  
    case '8':
      setChPins(No8);
      break;
    case '9':
      setChPins(No9);
      break; 
      
    /* special characters */
    case ' ':
      setChPins(Spc);
      break;
    case '!':
      setChPins(Exp);
      break;
    case '@':
      setChPins(Ats);
      break; 
    case '#':
      setChPins(Pnd);
      break;
    case '$':
      setChPins(Dlr);
      break;
    case '%':
      setChPins(Mod);
      break;
    case '^':
      setChPins(Xor);
      break;  
    case '&':
      setChPins(And);
      break;
    case '*':
      setChPins(Ast);
      break;
    case '(':
      setChPins(Opr);
      break;
    case ')':
      setChPins(Cpr);
      break;  
    case '-':
      setChPins(Mns);
      break;
    case '_':
      setChPins(Uln);
      break; 
    case '+':
      setChPins(Pls);
      break;
    case '=':
      setChPins(Eql);
      break;
    case '[':
      setChPins(Obr);
      break;
    case ']':
      setChPins(Cbr);
      break;  
    case '\\':
      setChPins(Bsh);
      break;
    case ';':
      setChPins(Sem);
      break;
    case ':':
      setChPins(Col);
      break;
    case '\'':
      setChPins(Apt);
      break;  
    case '"':
      setChPins(Qtm);
      break;
    case ',':
      setChPins(Com);
      break; 
    case '<':
      setChPins(Lth);
      break;
    case '.':
      setChPins(Prd);
      break;
    case '>':
      setChPins(Gth);
      break;
    case '/':
      setChPins(Fsh);
      break;  
    case '?':
      setChPins(Qst);
      break;
  }
  
  if (n < 4 && n >= 0) { /* indexes 0 to 3 are put on the left display */
    /* toggle write pin to store and preserve the current state */
    digitalWrite(WRL, LOW);
    digitalWrite(WRL, HIGH);
  } else if (n < 8 && n >= 4) { /* indexes 4 to 7 are put on the right display */
    /* toggle write pin to store and preserve the current state */
    digitalWrite(WRR, LOW);
    digitalWrite(WRR, HIGH);
  }
  return;
}

/* prints a string of no more than 8 recognized characters */
void hpdlPrint(String str)
{
  int len = str.length();
  for (int n = 0; n < len && n < 8; n++) {
    hpdlPutC(str.charAt(n),n);
  }
}

/* print an arbitrary length string as crawling text
   beginning and ending on the display, dwelling before
   and after the crawl sequence */
void hpdlPrintCrawl(String str, int dwell, double rate)
{
  int len = str.length();
  String toPrint = str;
  hpdlPrint(toPrint);
  delay(dwell);
  for (int n = 0; n < len-8; n++){
    toPrint.remove(0,1);
    hpdlPrint(toPrint);
    delay(int(1000/rate));
  }
  delay(dwell);
}

/* print an arbitrary length string as 
   crawling text beginning and ending 
   off the display */
void hpdlPrintFullCrawl(String str, double rate)
{
  hpdlPrintCrawl("        " + str + "        ", 0, rate);
}

/* print an 8-char string with an unscrambling effect */
void hpdlPrintUnscramble(String str, int dwell, double rate)
{
  int found[] = {0,0,0,0,0,0,0,0};
  bool done = false;
  String toPrint = "        ";
  while(!done){
    for (int index = 0; index < 8; index++){
      char c = rand() % 128;
      if (found[index] == 0){
        toPrint.setCharAt(index,c);
        if (str.charAt(index) == toPrint.charAt(index))
          found[index] = 1;
      }
    }
    hpdlPrint(toPrint);
    delay(int(1000/rate));
    
    int sum = 0;
    for (int i = 0; i < 8; i++){
      sum += found[i];
    }
    if (sum == 8)
      done = true;
    else
      done = false;
  }
  delay(dwell);
}

//void 

void setup()
{
  /* set output pins */
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(WRL, OUTPUT);
  pinMode(WRR, OUTPUT);
  
  /* set write pins to LOW to store the current state */
  digitalWrite(WRL, 0);
  digitalWrite(WRR, 0);
  
  /* CLEAR THE DISPLAY */ 
  /* set character select pins SET TO SPACE */
  digitalWrite(D6, 0);
  digitalWrite(D5, 0);
  digitalWrite(D4, 0);
  digitalWrite(D3, 0);
  digitalWrite(D2, 0);
  digitalWrite(D1, 0);
  digitalWrite(D0, 0);
  digitalWrite(A1, 1);
  digitalWrite(A2, 1); 
  digitalWrite(A1, 0);
  
  /* set write pins to HIGH to preserve the current state */
  digitalWrite(WRL, 1);
  digitalWrite(WRR, 1);
}


int x = 0;

void loop()
{
  hpdlPrint(" hello  ");
  delay(1000);
  hpdlPrint("  world ");
  delay(1000);
  hpdlPrint("hpdl1414");
  delay(1000);
  hpdlPrintCrawl("hello world crawl",1000,5);
  hpdlPrintFullCrawl("the quick brown fox jumped over the lazy dog!",8);

  hpdlPrintUnscramble("hpdl1414",5000,30);

};
