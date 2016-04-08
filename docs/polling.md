#Leg 6: Polling and dynamic caching


###Polling

After much trail and and error, we eventually decided to go with the naive method of using javascript to retrieve and show new incidents.  

The reason behind this decision was simply the difficulty we had integrating an alternative methods of websockets/socket.IO with our rails app (and I believe many other teams ran into similar problems).  Although there are issues with this, such as not every browser supports sockets, the main benefit of the websockets method as we saw it was that there was no constant pinging of our server, and if we had more time in the future we would like to tinker with it a bit more.  In the end we could not get it to properly integrate with our asset pipeline and play nicely with our datatables gem.  

The naive method we are using definately has a few downsides.  First, a user can modify the javascript to send queries to our server say every millisecond.  Second, it is somewhat inflexible in that it will continue polling even if a user is inactive or they don't want to see incidents.  Third, there is unconstrained pinging of our server that doesn't scale very will with many users.  That being said, the benefit is that it is straightforward. 

We use a gem called datatables that is very handy for displaying incidents.  It provides pagination, sorting of all columns ascending or descending, search, and some other stylings.  Therefore much of our work in javascript (besides learning the language for some of us) went in to interacting with this gem and its API.

The first thing we did was set the default sorting priority of our datatables to date (descending) then time (descending):  

This first means that new incidents will appear at the top of the table ( since they are displayed in order ) and second that 
the first time a user sees our incident index page it will display newest first. 

We then wrote a javascript function whose purpose was to use our get incidents endpoint via our api to query our server for our incidents.  It then compares the number of incidents it gets back to the number in the table.  If there are more than the number in our table we know a new one has been added, and we insert a new row into our table.  we then redraw the table to update the incidents in so that our user can see the new ones.  Note that this redrawing is not a refresh of the page of any sort, and to the user it appears as if a new incident has simply appeared at the top.  

This javascript function is done with set timeout, so that it will wait till the ajax is finished loading before querying again.  Also we decided to poll every minute to reduce the stress on our servers (as opposed to say 10 or 30 seconds).  As of now it appears to be functioning well.

###Images


###Caching


###Looking ahead

As mentioned before we would have liked to get websockets or sockets.io working, but it was tricky.  Our naive way works for a low volume of (not ill-intentioned) users.  Ideally we would like to take some preventative measures such as, since we have user log in implemented, limit the amount of queries from an individual users.  We ideally would have a rate limiting system such as was discussed in class no just because of this polling system, but for users accessing our API in general.  We do feel for this leg our method works ok.
