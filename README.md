# COMP 318 - Project 3

#### Greedy & Dynamic Programming Algorithms

##### by Paedar Rader

- - -

**Description:** This program implements two different Algorithms, for a tax bill system, via the 'Banana Republic' and their desire for a new currency to combat their 'ever increasing inflation'. These Algorithms give the user two different ways to pay their taxes, utilizing both the Greedy Algorithm, and Dynamic Programming. Each of these have their differences, and vary in their runtime, space complexity, and general practicality.

- - -

### Test Cases:

1. **Basic Number**
First, we test with a basic value, say, $43,865. Our name is "Steve", and this is the program output given this information:

<code>Welcome to the IR$ of Banana Republic!
Please enter your name: Steve
What is your tax $$$ due?: 43865
<br>
Plan 1: The Greedy Approach
Tax Due: $43865
<br>
 Bills	Num	Subtotal
$95000	x 0	= $0         	$0          
$32001	x 1	= $32001     	$32001      
 $5001	x 2	= $10002     	$42003      
  $701	x 2	= $1402      	$43405      
  $101	x 4	= $404       	$43809      
    $1	x 56	= $56        	$43865      
<br>
Total number of bills needed: 0 + 1 + 2 + 2 + 4 + 56 = 65
—-----------------------------------------------------------------
./a.out  0.00s user 0.00s system 0% cpu 12.237 total
- - -
Plan 2: The Dynamic Programming Approach
Tax Due: $43865
<br>
 Bills	Num	Subtotal
$95000	x 0	= $0         	$0          
$32001	x 1	= $32001     	$32001      
 $5001	x 2	= $10002     	$42003      
  $701	x 2	= $1402      	$43405      
  $101	x 4	= $404       	$43809      
    $1	x 56	= $56        	$43865      
<br>
Total number of bills needed: 0 + 1 + 2 + 2 + 4 + 56 = 65
—-----------------------------------------------------------------
./a.out  0.04s user 0.01s system 0% cpu 5.897 total</code>

We can observe the following aspects of this test case:
- Execution Time (Greedy): 0.0s
- Execution Time (Dynamic): 0.01s
- Overall Exec. Time: 0.01s
<p>As we can see, the Greedy is more efficient in its execution time, but not by much, as the tax amount is still fairly small in relation to what will cause the program to be slow, on most machines. For more, refer to the <em>Overall Complexities</em> section.</p>
<br>

2. **Very Large Number**

For this next test, we are going to test the extreme, very higher-end, efficiency of both algorithms, using the same name, and a tax amount of $214748364 <em>(One less number of numbers as the C++ Int Max Limit, 2147483647. My personal laptop was unable to compile with the test case of one less than the limit, but it is possible with better hardware, and better comiling softwares.)</em>

<code>Welcome to the IR$ of Banana Republic!
Please enter your name: Steve
What is your tax $$$ due?: 214748364
<br>
Plan 1: The Greedy Approach
Tax Due: $214748364
<br>
 Bills	Num	Subtotal
$95000	x 2260	= $214700000 	$214700000  
$32001	x 1	= $32001     	$214732001  
 $5001	x 3	= $15003     	$214747004  
  $701	x 1	= $701       	$214747705  
  $101	x 6	= $606       	$214748311  
    $1	x 53	= $53        	$214748364  
<br>
Total number of bills needed: 2260 + 1 + 3 + 1 + 6 + 53 = 2324
—-----------------------------------------------------------------
./a.out  0.00s user 0.00s system 0% cpu 3.118 total
- - -
Plan 2: The Dynamic Programming Approach
Tax Due: $214748364
<br>
 Bills	Num	Subtotal
$95000	x 2242	= $212990000 	$212990000  
$32001	x 54	= $1728054   	$214718054  
 $5001	x 6	= $30006     	$214748060  
  $701	x 0	= $0         	$214748060  
  $101	x 3	= $303       	$214748363  
    $1	x 1	= $1         	$214748364  
<br>
Total number of bills needed: 2242 + 54 + 6 + 0 + 3 + 1 = 2306
—-----------------------------------------------------------------
./a.out  154.25s user 22.02s system 93% cpu 3:07.60 total
</code>

We can observe the following aspects of this test case:
- Execution Time (Greedy): 0.0s
- Execution Time (Dynamic): 154.25s (2 and 1/2 minutes)
- Overall Exec. Time: 154.25s
<p>This larger test case is a great example of how as <strong>n</strong> gets larger, the time complexity increases quadratically. The Greedy Approach finishes instantly, while the Dynamic Approach takes over 2 minutes to finish. Some of this may be a result of hardware, but the differences between machines still relies heavily on the time complexity of the algorithm itself. Also, the number of bill denominations isn't that large, with there only being a difference of 18. For more, refer to the <em>Overall Complexities</em> section.</p>
<br>

3. **No Major Difference in Denominations**

For the final test, we are going to test another realistic number, but larger than test one, but much less than test two. We are going to try $428,716, a number in which there shouldn't be a large difference between the number of denominations, given the size of the tax amount.

<code>Welcome to the IR$ of Banana Republic!
Please enter your name: Steve
What is your tax $$$ due?: 428716
<br>
Plan 1: The Greedy Approach
Tax Due: $428716
<br>
 Bills	Num	Subtotal
$95000	x 4	= $380000    	$380000     
$32001	x 1	= $32001     	$412001     
 $5001	x 3	= $15003     	$427004     
  $701	x 2	= $1402      	$428406     
  $101	x 3	= $303       	$428709     
    $1	x 7	= $7         	$428716     
<br>
Total number of bills needed: 4 + 1 + 3 + 2 + 3 + 7 = 20
—-----------------------------------------------------------------
./a.out  0.00s user 0.00s system 0% cpu 9.939 total
- - -
Plan 2: The Dynamic Programming Approach
Tax Due: $428716
<br>
 Bills	Num	Subtotal
$95000	x 3	= $285000    	$285000     
$32001	x 4	= $128004    	$413004     
 $5001	x 3	= $15003     	$428007     
  $701	x 1	= $701       	$428708     
  $101	x 0	= $0         	$428708     
    $1	x 8	= $8         	$428716     
<br>
Total number of bills needed: 3 + 4 + 3 + 1 + 0 + 8 = 19
—-----------------------------------------------------------------
./a.out  0.32s user 0.02s system 6% cpu 5.092 total
</code>

We can observe the following aspects of this test case:
- Execution Time (Greedy): 0.0s
- Execution Time (Dynamic): 0.32s
- Overall Exec. Time: 0.32s
<p>Once again, the Greedy option is much more efficient. Of course, all of this testing does rely on the hardware of your device, but the differences in times are so drastic that even if you had more efficient hardware the difference would still be notable. Also, the Dynamic option only has one less bill denomination, making Steve have to decide as to what is really more important. For more, refer to the <em>Overall Complexities</em> section.</p>
<br>

**To be noted:** *The actual output will include the option for the user to select which choice they want, as well as some messages and prompts if the user enters zero, or anything below zero. Also, formatting is very different, and slightly incorrect on the README file, as the formatting is done specifically for terminal C++ output. So, to see these results, please use the interface itself via terminal.*

### Overall Complexities:
-  Time Complexity (Greedy): O(n)
    - *Depends on the size of the tax, but this is also the worst case, as it never takes longer than <strong>n</strong>*, as there is only one while loop going through the entire list of possibilites, via the class vector arrays.
- Time Complexity (Dynamic): O(n * tax)
    - *This is because we run through the list initially, but must multiply it by the tax amount, as we are constantly checking against every possible combination to find the smallest bill denomination combo, which requires a lot of time.*
- Space Complexity (Greedy): O(1)
    - *We do not use any additional storage, besides the tax amount, as the rest is being stored in the changePlan class data members.*
- Space Complexity (Dynamic): O(n * tax)
    - *There are two 2-d vector arrays being utilized, 'dp' and 'selectedBills' to store the combos for the smallest possible bill denominations. These arrays are used temporarily to store the values during processing, and is eventually moved into the 'plan' array, of the changePlan class.*

**Which Approach is Better?**
In general, the Greedy Approach is by far the more efficient option, and therefor, would probably be what you want when it comes to running a program, as it doesn't take up device resources nearly as much as the Dynamic Approach. However, when it comes to practically speaking, if you want less physical bill denominations, the Dynamic Approach is clearly going to give you such, but it will take longer to run. *All of that to say,* the Greedy Algorithm Approach is the far better option, efficiency wise. However, the Dynamic Programming Approach does give the user a smaller number of denominations, but like mentioned before, it is up to the user to decide the efficiency tradeoff given the runtime. 

- - -

<table>
    <tr>
        <td>
        <h3><strong>File List:</strong></h3>
        <ul>
            <li>main.cpp</li>
            <li>Makefile</li>
            <li>README.md</li>
        </ul>
        </td>
        <td>
        <h3><strong>Dependencies:</strong></h3>
            <ul>
                <li>C++ Version 11</li>
                <li>Makefile</li>
                <br><br>
            </ul>
        </td>
        <td>
            <h3><strong>Honor Pledge:</strong></h3>
            <ul>
                <li>I have abided by the Wheaton College Honor Code in this work: <em> Paedar Rader</em></li>
            </ul>
            <br>
            <br>            
        </td>
    </tr>
</table>

- - -

### How to Compile & Run:

1. When in the proper main directory, run the following command:
`make`

2. This will create a executable called 'change_plans'. To execute it, run the following command:
`./change_plan`

3. The program is now running. When completed, if you want to run again, simply follow <strong>step 2</strong> again.

- - -

### Development Log:

- April 29th, 2024: Started Project, initialized files, created main
- April 30th, 2024: Created the 'ChangePlan' class, and all of its data members, and methods, per the project specs
- April 30th, 2024: Implemented, and completed, the Greedy Algorithm
- May 1st, 2024: Started working on Dynamic Programming, Bottom-Up, Algorithm Approach
- May 2nd, 2024: Implemented, and completed, Dynamic Programming Algorithm, also, made print_plan method for code reuse.
- May 2nd, 2024: Initialized all files to GitHub
- May 2nd, 2024: Completed Makefile, main.cpp, README.md
- May 2nd, 2024: Pushed all changes to Github
- May 2nd, 2024: Created TAR compression file, submitted to canvas

- May 2nd, 2024 - 9:50pm: Project Completed

Github Page: https://github.com/paedarr/comp318-project3


- - - 

### Acknowledgments

This project, by Paedar Rader, is based on the Project Assignment by Martin Gagne at Wheaton College, via adaptation for COMP 318 by Tony Tong of Wheaton College. 