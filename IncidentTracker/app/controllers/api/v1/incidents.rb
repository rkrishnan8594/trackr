module API
  module V1
    class Incidents < Grape::API
      include API::V1::Defaults

      resource :incidents do
        desc "Return all incidents"
        get "", root: :incidents do
          Incident.all
        end

        desc "Return an incident"
        params do
          requires :id, type: String, desc: "ID of the incident"
        end
        get ":id", root: "incident" do
          Incident.where(id: permitted_params[:id]).first!
        end

        desc "Submits an incident"
        params do
          requires :location, type: String, desc: "Location of the incident"
          requires :severity, type: String, desc: "Severity of the incident"
        end
        post do
          Incident.create!({
            location: params[:location],
            severity: params[:severity]
          })
        end
      end
    end
  end
end
