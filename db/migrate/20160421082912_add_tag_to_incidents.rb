class AddTagToIncidents < ActiveRecord::Migration
  def change
    add_column :incidents, :tag, :string
  end
end
