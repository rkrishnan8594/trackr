# API Report

### Documentation URL: 


###Gems and Tools used:
* grape
* grape-active_model_serializers
* grape-swagger-rails
* rack-cors

After some research we decided to use grape to build our API.  The first reason is performance.  According to blogs such as http://www.datto.com/blog/a-framework-comparison-of-grape-vs-railsapi-part-1-performance, grape processes requests almost twice as fast as the basic rails API.  Another reason is that grape allows for very readable and modular syntax.  As will be discussed in the implementation section it allows for separation by models, easy integration of comments and documenation with the code, versioning, and default modules for global setting such as error messages.  

For handling our documentation we decided to use swagger, much of which was handled with the grape-swagger-rails gem.  There were a number of reasons for swagger - we liked the look, the clear of the Verb, endpoints, paramaters and description.  But what really sold us on swagger was the fact that it allows for trying/using the API from within the documentation! it allows you to input parameters, send the request and shows you the response body, response code, response headers, request URL and Curl.  Not only does it make the api very easy to understand, it also was incredibly helpful when we were testing our API.  

###Implementation

Setting up grape - 

We first added the above gems to our gemfile and installed. In our controller we created a folder called api. Within that we created a base.rb file which simply mounts our base class on the application as such: 

    mount API::V1::Base 
What the mounting does is it essentially tells rails that another application exists there, and makes the functionality available in the Rails app. 

Then since grape supports versioning a folder called V1. we created 4 rb files within this folder - base.rb, default.rb, incidents.rb, users.rb.  In our base file we accomplished two things, setting up our swagger documentation and mounting our incidents and user modules modules. In our defaults file, we added helper functions to be usable across all modules, as well as error handling such as 

        rescue_from ActiveRecord::RecordNotFound do |e|
          error_response(message: e.message, status: 404)
        end
In our users.rb and incidents.rb file we implemented the core functionality of the api such as GET and POST requests. For incidents we added the basic crud operations and two ways to get users, either get all or get by ID.  For users we added only get all and get by id.  The documentation should cover these functions well.

The final step was mounting our api in our routes.rb file in the config folder as such:

    Rails.application.routes.draw do  
    mount API::Base, at: "/"
  end  

Setting up Cors-
The idea behind Cors is to allow our api to handle cross-site requests (requests from different domains).  Setting up this gem allows us to send data across different domanis/sites. to do this we simiply installed the gem and added: 

    module Api  
    class Application < Rails::Application
      config.middleware.use Rack::Cors do
        allow do
          origins "*"
          resource "*", headers: :any, methods: [:get, 
              :post, :put, :delete]
        end
      end
      config.active_record.raise_in_transactional_callbacks = true
    end

the origins line allows our api to accept requests from any domain, and the resouces line allows for any of our resources to be added

Setting up Serialization-
We used a serializer for two purposes.  The first was to transform our ruby objects into valid Json, the second is it allows us to choose what information to give out.  For example in users we only wanted to display email, name, last name, role, and id.  So we created a folder serializers in our app folder, and added user_serializer.rb and incident_serializer.rb files.  Our user_serializer.rb file is simply: 

    class UserSerializer < ActiveModel::Serializer
      attributes :id, :email, :first_name, :last_name, :role
    end
    
    

Setting up Swagger-
At this point since we defined swagger parameters in our base.rb file, all that was left was to mount swagger in our routes.rb file in config as such:

    mount GrapeSwaggerRails::Engine, at: "/documentation"

this set up our swagger at /documentation extenion of our url and we were done! We also linked to this page from our application layout view.


###Looking Ahead

The next big steps in the project deal with users
