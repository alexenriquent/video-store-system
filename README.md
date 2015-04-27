## Video Store Management Information System ##

The video store leases movie DVDs to customers. The information about a movie DVD includes title, starring, director, duration, genre, classification, and release date. The genre of a movie may be Drama, Adventure, Family, Action, Sci-Fi, Comedy, Animated, Thriller, or Other. A movie is classified as General (G), Parental Guidance (PG), Mature (M15+), or Mature Accompanied (MA15+). The video store may have multiple DVDs of the same movie.

It is the policy of the video store that all the customers must register with the system through the store staff before they can rent DVDs from the store. When a customer is being registered with the system, his full name, residential address, and a contact phone number are recorded in the system. The system also keeps the information about the DVDs currently being rented by all the registered customers. When a registered customer rents a DVD, the DVD is added to the customer’s renting record; and when the customer returns the DVD to the store, the DVD is removed from the customer’s record. A registered customer is allowed to rent up to 10 DVDs. However, a customer is not allowed to rent two DVDs of the same movie.

It is assumed that both the customers’ names and the titles of the movies are unique, and that renting fees are manually handled by the staff, which means the system does not need to handle renting fees.

### System Requirements ###

Both the staff and all the registered customers can use the system. However, authentication must be done before they are allowed to use the system. It is assumed that the username and the password for the staff are ‘staff’ and ‘today123’, respectively, and that the username of a registered customer is the customer’s name in one word. For example, if a customer’s surname and given name are ‘Smith’ and ‘John’, respectively, then the customer’s username is ‘SmithJohn’. The password of a registered customer is a positive whole number of four (4) digits.

The system has a sub-menu that allows the staff to do the following:

* Add DVDs of a new movie to the system
* Add DVDs of an existing movie to the system
* Remove a DVD from the system (a DVD can be removed only when it is not being rented)
* 􏰁Register a new customer with the system
* Remove a registered customer from the system (a customer can be removed only when he/she is not renting any DVDs)
* 􏰁Find a customer’s contact phone number, given the customer’s name.
* Find customers who are currently renting a particular movie, given the movie’s title

The system also has another sub-menu that allows a registered customer to do the following:

* Browse all the movies by title in alphabetical order and show the number of DVDs available in the store for each of the movies
* Display all the information about a movie, given the title of the movie
* 􏰁Rent a DVD
* Return a DVD
* List current rented movies
* Display the top 10 movies rented by the customers in the history in the descending order of the number of rentals (how many times each movie has been rented). The display should include the title of the movie and how many times that the movie has been rented.