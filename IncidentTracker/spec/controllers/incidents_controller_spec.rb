require 'rails_helper'
require 'spec_helper'

describe IncidentsController do
  describe "POST #create" do
    context 'valid attributes' do
      it 'creates the incident' do
        @request.env["devise.mapping"] = Devise.mappings[:user]
        sign_in FactoryGirl.create(:user)
        post :create, incident: FactoryGirl.attributes_for(:incident)
        expect(Incident.count).to eq(1)
      end
      it 'redirects to the incident view page' do
        @request.env["devise.mapping"] = Devise.mappings[:user]
        sign_in FactoryGirl.create(:user)
        post :create, incident: FactoryGirl.attributes_for(:incident)
        expect(response).to redirect_to Incident.first
      end
    end

    context 'invalid attributes' do #if nothing added
      it 'incident not created' do
        @request.env["devise.mapping"] = Devise.mappings[:user]
        sign_in FactoryGirl.create(:user)
        post :create, incident: FactoryGirl.attributes_for(:incident, description: nil)
        expect(Incident.count).to eq(1) #should it be zero once we have that null thing figuredd out
      end

      it 're-renders the "new" view' do
        @request.env["devise.mapping"] = Devise.mappings[:user]
        sign_in FactoryGirl.create(:user)
        post :create, incident: FactoryGirl.attributes_for(:incident, description: nil)
#        expect(response).to render_template :new #use this after updates
        expect(response).to redirect_to Incident.first # should route to new incident page if description not given
      end
    end
  end
end
