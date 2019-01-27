#include <Arduino.h>

/* DL1414 character set definitions:
 * Each character is defined as an 8 char long string of 1s and 0s that is NULL
 * terminated. Each char in the string stands for the state of an input pin on
 * the DL1414 chip and holds a binary value of either TRUE or FALSE. The
 * leftmost char in the string represents the state of pin D6 on the DL1414 and
 * the rightmost char represents the state of D0.
 */
/* SPECIAL CHARACTERS */
#define Spc "0100000" /* [ ] white space (blank) */
#define Exp "0100001" /* [!] exclamation point */
#define Ats "1000000" /* [@] at sign */
#define Pnd "0100011" /* [#] pound sign */
#define Dlr "0100100" /* [$] dollar sign */
#define Mod "0100101" /* [%] percent sign */
#define Xor "1011110" /* [^] carrot */
#define And "0100110" /* [&] ampersand */
#define Ast "0101010" /* [*] asterisk (multiplication) */
#define Opr "0101000" /* [(] open parentheses */
#define Cpr "0101001" /* [)] closed parentheses */
#define Mns "0101101" /* [-] minus sign (dash/hyphen) */
#define Uln "1011111" /* [_] underscore */
#define Pls "0101011" /* [+] plus sign */
#define Eql "0111101" /* [=] equals sign */
#define Obr "1011011" /* [[] open bracket */
#define Obr "1011101" /* []] closed bracket */
#define Bsh "1011100" /* [\] back slash  */
#define Sem "0111011" /* [;] semicolon */
#define Col "0111010" /* [:] colon */
#define Apt "0100111" /* ['] apostrophe */
#define Qtm "0100010" /* ["] quotation mark */
#define Com "0101100" /* [,] comma */
#define Lth "0111100" /* [<] less-than sign */
#define Prd "0101110" /* [.] period (decimal) */
#define Gth "0111110" /* [>] greater-than sign */
#define Fsh "0101111" /* [/] forward slash (division) */
#define Qst "0111111" /* [?] question mark */

/* NUMBERS */
#define No0 "0110000" /* [0] zero */
#define No1 "0110001" /* [1] one */
#define No2 "0110010" /* [2] two */
#define No3 "0110011" /* [3] three */
#define No4 "0110100" /* [4] four */
#define No5 "0110101" /* [5] five */
#define No6 "0110110" /* [6] six */
#define No7 "0110111" /* [7] seven */
#define No8 "0111000" /* [8] eight */
#define No9 "0111001" /* [9] nine */

/* LETTERS */
#define _A_ "1000001" /* [A] capital a */
#define _B_ "1000010" /* [B] capital b */
#define _C_ "1000011" /* [C] capital c */
#define _D_ "1000100" /* [D] capital d */
#define _E_ "1000101" /* [E] capital e */
#define _F_ "1000110" /* [F] capital f */
#define _G_ "1000111" /* [G] capital g */
#define _H_ "1001000" /* [H] capital h */
#define _I_ "1001001" /* [I] capital i */
#define _J_ "1001010" /* [J] capital j */
#define _K_ "1001011" /* [K] capital k */
#define _L_ "1001100" /* [L] capital l */
#define _M_ "1001101" /* [M] capital m */
#define _N_ "1001110" /* [N] capital n */
#define _O_ "1001111" /* [O] capital o */
#define _P_ "1010000" /* [P] capital p */
#define _Q_ "1010001" /* [Q] capital q */
#define _R_ "1010010" /* [R] capital r */
#define _S_ "1010011" /* [S] capital s */
#define _T_ "1010100" /* [T] capital t */
#define _U_ "1010101" /* [U] capital u */
#define _V_ "1010110" /* [V] capital v */
#define _W_ "1010111" /* [W] capital w */
#define _X_ "1011000" /* [X] capital x */
#define _Y_ "1011001" /* [Y] capital y */
#define _Z_ "1011010" /* [Z] capital z */

void setup()
{

}

void loop()
{

}
