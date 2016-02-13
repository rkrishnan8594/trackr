class Incident < ActiveRecord::Base
  belongs_to :user
  has_and_belongs_to_many :categories

  def set_user!(user)
    self.user_id = user.id
    self.save!
  end
end
