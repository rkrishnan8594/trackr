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
