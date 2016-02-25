FactoryGirl.define do
  factory :user do
    email         "test@email.com"
    password      "XXXXXXXXX"
    first_name    "First"
    last_name     "Last"
    role          "Student"
  end
end
