#Leg 6: Polling and dynamic caching


###Polling

After much trail and and error, we eventually decided to go with the naive method of using javascript to retrieve and show new incidents.  

The reason behind this decision was simply the difficulty we had integrating an alternative method of websockets/socket IO with our rails app (and I believe many other teams ran into similar problems).  The main benefit of the websockets method as we saw it was that there was no constant pinging of our server, and if we had more time in the future we would like to tinker with it a bit more.  In the end we could not get it to properly integrate with our asset pipeline and play nicely with our datatables gem.  

The naive method we are using definately has a few downsides.  First, a user can modify the javascript to send queries to our server say every millisecond.  Second, it is somewhat inflexible in that it will continue polling even if a user is inactive or they don't want to see incidents.  Third, there is unconstrained pinging of our server that doesn't scale very will with many users.  That being said, the benefit is that it is straightforward. 

We use a gem called datatables that is very handy for displaying incidents.  It provides pagination, sorting of all columns ascending or descending, search, and some other stylings.  Therefore much of our work in javascript (besides learning the language for some of us) went in to interacting with this gem and its API.

The first thing we did was set the default sorting priority of our datatables to date desc then time:  

This first means that new incidents will appear at the top of the table ( since they are displayed in order ) and second that 



###Caching


###Looking ahead

