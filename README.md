Leg 1: Wireframe and Model

# Design
After reviewing the information provided to us from Tina, we've decided to design the data schema for the application using four tables: Users, Incidents, Categories, and Departments.

### Users
The users in the system will be created by a simple authentication system, where one would input their universal PIN and password for the research institution to create an account. The rest of the information for the user (first name, last name, role, department, email) would be pulled from the universal account.

### Incidents
Incidents represent the filed incident reports submitted by users. Various data fields that are a part of the incident table will be populated by data filled out by the user in the report form (description, location, category, severity). Other fields, such as user, department and datetime, would be populated automatically. The 'status' and 'comments' are initially blank fields that are to be filled out by an administrator.

### Categories
These represent the various types of incidents that we expect to be most common (fire, fallen tree, flooding, etc). On incident forms, there will be an option for 'other' if one does not match. Each of these categories is mapped to a specific department (represented by it's ID in the table).

### Departments
These are simply the departments that comprise Operations Services. The members of these departments will have access to view and take action on various incidents. Each department also has a number of categories mapped to them. When an incident is filed with a category that maps to their department, they can view it on their timeline and respond accordingly.



Leg 2: MVP
### Architecture and Tools
We used Ruby on Rails for the implementation of the MVP.  This was primarily because of the following:
    Inbuilt RESTful design
    Strict to adherence to MVC design structure
    Object Relational Mapping
    Rails is very well established platform in the professional developement scene
    Rails has a very elementary learning curve
    
We used Postgres for the following reasons:
    We are building for 'n' users 
    Well known for reliability and stability
    Cross platform support
    Good performance
    
We used only the default gems packages with Rails
No additional APIs or dependencies were used

### Group Work/Effort Estimation
Average hours per person learning ruby : 4hr
Average hours per person developing/testing/designing/researching/etc MVP: 24hr
Challanges we faced:
  Installation and setup configuration and version control
      We have 2 windows users, one mac user, and one linux user so getting everyone on the same page was difficult
  Learning github
      Only one of our members had used github before, and learning branching, merging, and all other features was difficult
  Deciding which if any gems to use
      We looked into bootstrap, jquery mobile, datatables among other gems/packages and spent a lot of time testing features
      before deciding to add our own styles
  Design/architecture
      We spent a lot of time trying to create a simple design theme that would be appropriate for our diverse users
      We spent a lot of time discussing the scope of the mvp and what functionality/data we thought was really necessary for 
      the MVP
      
      
      
      




    
    


