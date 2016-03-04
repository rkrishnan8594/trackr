# Static Performance Report

### Tools Used
Yslow, Pagespeed Tools

The suggestions these two tools gave us had the least amount of overlap, so therefore we felt that together they provided a good general measurement of our optimizations

### Initial state of the site
These are the results for the incidents timeline/table page. The other pages were all as good or better.

When using Yslow, our site actually recieved an A as the original score, although it was the lowest A possible (90).  There were 4 change suggestions that we did not get an A on.
* F - use a CDN
* F - expires headers
* B - compress components with gzip
* C - use cookie-free domain

When running Pagespeed we recieved an 88% for desktop.  There were also 4 suggestions
* render browser caching
* remove blocking JS
* enable compression with gzip
* minify javascript


### Discussion of Changes
The first change we made was to compress components with gzip.  After some research about rails asset pipeline, we found that doing this was as simple as adding "use Rack::Deflater" to our config file.  This solved the issue for both of our tools.

The next big change we made was setting up a CDN to serve our static content.  This process took the most time.  We decided to use S3 buckets in AWS to store our static content/images.  The main reason we decided to use S3 was our research showed that while s3 is a bit slower than some cdns such as Cloudfront, it has better storage and bandwidth costs, which is something we felt we wanted to prioritize.  Implementing this brought our CDN grade on Yslow up to an A.

We found that solving the remove blocking JS from pagespeed was as simple as moving javascript to the bottom of the page.  We also minified our js using the uglifier gem

The next change we made was to add expires headers.  the way we did this was to add "config.static_cache_control = "public, max-age=31536000"" to our application.rb file in config.  This adds a far future expiring header to our files (I believe it is 10 years).  However we found that this did not help for the datatables gem we used to style our table with sorting, pagination, search, etc.  Because these files were unaffected, we were still receiving an F for the expires headers grade.  

We spent a lot of time trying to deal with this, but we found it very tricky to deal with the datatables gem.  Eventually the best idea we had to fix this was to instead of using datatables as a gem, reference the stylesheets and js files for the plug in externally since we found ones that were already on a public CDN.  This method solved our expiration problems with the plug in on Yslow, upgrading that to an A, but it caused additional ones as well - the tags of some of the images in the CDN were not configured correctly and this fell to a C.  Since this was lower on the list it resulted in an increase in performance, but it is another issue we still have to solve.  This method also caused an issue in pagespeed - these external sheets were considered render-blocking CSS and it wanted them to be elimated.

### Final Results
Once again these results are on the the incidents timeline, since all other pages scored at least as well

When running Yslow our perforamce increased from A(90) to to A(97), which we consider to be a good/solid increase.  The places where performance can be improved are were
* C Add expires headers
* C configure entity tags
* D use cookie free domains

The first two are related to the datatables gem again. I may change this comment, but we are still in the process of experimenting with fixing these issues, so at the momment our css for datatables is on a CDN and the javascript is not, so that is what is causing a C for the first two.  As for using cookie free domains, spent a lot of time configuring s3 for static content and images and hoped that we would be able to take care of it along the way, but unfortunately it has not yet been resolved.  Currently we are still working on fixing this one

When running pagespeed our performance increesed from 88% to 91%. The main reason this speed up isn't as much as we wanted was due to setting the datatables plug in as an external cdn. All the other errors are solved except this new render-blocking css now with datatables as an external CDN.  

In conclusion we were able to solve almost everything except the problems relating to the datatables gem and the cookie free domain.  Our current plan is to spend a bit more time trying to deal with the datatables (since it does add nice looks and functionality), but if we can't we may look for alternatives for our timeline.  
