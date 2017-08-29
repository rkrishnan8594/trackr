class AddFieldsToUsers < ActiveRecord::Migration
  def change
    add_column :users, :first_name, :string
    add_column :users, :last_name, :string, :null => false
    add_column :users, :role, :string, :null => false
  end
end
