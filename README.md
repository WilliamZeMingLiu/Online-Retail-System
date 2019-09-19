William Liu

This is my online retail system program.  A very simple program, it first takes in a txt file that contains information of the item that is to be sold.  After that, it takes in information of users.  My program then creates User and Product objects based on the information provided.  The program allows the user to login/logout of their account. Users can use a search engine to search products by terms, using multiple terms to see if product contains ALL search terms or all products that contain at least 1 of these terms.  Users can view their selected cart, buy cart, and add reviews for selected products.

**How to compile code:**
To compile, use the make file, inputing just the input "make"
**To run:** ./amazon database.txt 

Part 1)
For part 1, I created 4 functors with different sorting parameters.  The first one is case by ascending order,
therefore the default sort order.  The second is descending, so just flip the ">" operator.  Third one is case
insesitive, so simply just convert all characters to lowercase to equal it out.  For the final one, same as the 
the first one but I removed the trailing whitespaces by using my own for loop

Part 2)
Very simple, I simply just implemented mergesort and made it a template so that it can be used generally for 
any type of datatype and functor requirement.

Part 3)
Created a new function addReview() to add reviews to existing objects.  For this, to store each review, I created
a new member variable for Product that was a vector of Review objects, since a product can have multiple reviews

Part 5)
Revised the search function in mydatastore.cpp so that it will use the two functors I just added at the top of 
mydatastore.cpp so that I can use mergesort to sort by review and by alphabetic name ordering.  Functors are
very straightforward, since string and int support < comparisons.

Part 6)
Very simple, I simply added the LOGIN and LOGOUT and created a new string variable that is initialized before
the menu while loop.  When user chooses LOGIN, the string variable will now contain the username and will be
passed down to the other functions, so there is no need to edit the other mydatastore functions that take in
the username

Part 7)
Created the adding and viewing interface for amazon.cpp.  For this, ADDREV was a bit of a challenge and very 
tedious since I had to make sure that each parameter is in appropriate style                                                                                                         