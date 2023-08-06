# *makeFile for ATmega32*

- ###  Flags to create object file

|Flag              | Electivity  | Description |
| :--------------: | :---------: | :-----------|
| ***-wall***          | **optional**    |<p> Generate warning messages </p>|
| ***-g2***          | **optional**   | <p>Giving more debugging information</p>|
| ***-gstabs***      | **optional**   | <div><p>Giving more debugging information in STABS format</p> <p>See the comparison between -g and -gstabs</p></div> |
| ***-O0 or -Os***   | **recommended**  |<div><p> it sets the level of optimization like -O1 and -O2.</p> <p class="capitalize">If you removde it the defalut is -O0</p> <p class="capitalize">you could benefit from it if you use the inline function</p></div>  |
|***-fpack-struct*** | **optional**| to optimize memeory size by structure packing avoiding padding|
|***-fshort-enums*** | **optional**| avr-gcc will choose the smallest intger type to represent ur enum |
|***-ffunction-sections***|**optional**|place each function into its own individual section in the compiled binary|
|***-fdata-sections***| **optional** |place each global or static variable into its own individual section in the compiled binary|
|***-std=gnu99***| **optional** | it indicates that the code should be compiled using the GNU C99 standard |
| ***-funsigned-char*** | **recommended** | it is used to specify that the char type should be treated as unsigned by default| 
| ***-funsigned-bitfields*** | **optional** |treat bit-fields as unsigned by default| 
<div>
    <div>the following command is full command</div> 
    <code>avr-gcc -wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99</code>
</div>