class Incident < ActiveRecord::Base
  belongs_to :user
  has_and_belongs_to_many :categories
  validates :location, :severity, :presence => true
  before_save :override_field

  def override_field
    if self.status.nil?
      self.status = 1
    end
  end

  def set_user!(user)
    self.user_id = user.id
    self.save!
  end
end
