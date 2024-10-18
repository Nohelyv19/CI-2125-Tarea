/***********************
*
* EXPRESIONES DIÁDICAS 1
*
**********************/
#include &lt;stdio.h&gt;
int main() {
int x,y;
for (;;) {
printf(&quot;Introduzca el valor de x = &quot;);
scanf(&quot;%d&quot;,&amp;x);
printf(&quot;Introduzca el valor de y = &quot;);
scanf(&quot;%d&quot;,&amp;y);
printf(&quot;\n%d + %d = %d\n\n&quot;,x,y,x+y);
}
return 0;
}
/*
*
* printf(&quot;\n%d || %d = %d\n&quot;,x,y,x||y);
*
*/