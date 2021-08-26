# Queue-for-prefix-expressions

This project creating for solution of prefix expression. Prefix expressions , wraps around the expression tree in order : top , right and left.<br> For example : <br><br>
![resim](https://github.com/SeymaAtmaca/Queue-for-prefix-expressions/blob/main/images/prefix_2.png)

<br>
<hr> 
You have to solve this prefix expression :<br>
        1)top --> +  (Now, you are in left tree )<br>
        2)top --> + * (This is top of the left tree )<br>
        3)left --> + * 2 (We haven't top , so we must right node of the little left tree)<br>
        4)right --> + * 2 6 <br>
        5)top of the right side --> + * 2 6 /<br> 
        6)left of the left tree --> + * 2 6 / 3 <br>
        7)right of the left tree --> + * 2 6 / 3 8 <br>

So now , you have a prefix expression ( + * 2 6 / 3 8) 
<br>
<hr> 
<br>
If you want to solve any prefix expression , you must go to backward.

<br><br>
<hr>
<br><br>




        

