# Kaprekar's Constant
Work in progress!

A command line c++ representation of the mathematical phenomena called "Kaprekar's Constant". <br/>

The mathematics goes as follows:<br/>
    1 - Take a 3 or 4 digit number, with at least 2 unique digits (including 0).<br/>
    2 - Sort the number by biggest digits descending and by smallest digits ascending (4321   and  1234).<br/>
    3 - Substract the bigger number by the smaller (4321 - 1234), get the next number.<br/>
    4 - Repeat steps 1-3, until the next number results in the same value as the previous (becomes constant).<br/>
    5 - That number is Casper's Constant.<br/>


My program asks the input from the user. <br/>
It has to be an integer, with the following requirements: 3 or 4 digits long, and has to have 2 unqiue digits.<br/>
These are the requirements to get the constant of the mathematical phenoma.<br/>

# Progress update - 25.10.2019 1 AM <br/>

I started this application with the intent of putting all my programming knowledge so far to practical use. My goal was to
try to make it as clean as I possibly can, in regards to human readability and also application efficiency. However, tonight 
I have realised I was off to a bad start. 

My style of working in this project prioritized functionality of the program first, and then cleaning it up or improving it, 
after, once I got tangled too much. This is part of my learning proccess and why I wanted to do this in the first place. I have 
implemented one "function" at a time in this project, but I haven't made them very neetly. I had a lot of code in my main
function, and also made use of goto statements. 

My program has always worked exactly like I want it to, and is rigorously tested after every addition of functionality. 
I was still curious wether I was going about the structure of the code correctly, so I researched wether my ways were good.
I have found out that the goto statement is quite old and can cause spaghetti code, which is why I changed it's use with a while
loop. I have also split my main function code into smaller functions, making it way easier to track of what's going on.

I am very satisfied with this project so far, even though I haven't yet completed it (the sorting and calculating part left).
It's given me a solid knowledge of the architechure of a c++ application, and I now make less spaghetti code. 


    


