kubectl delete -f kindling-prometheus-servicemonitor.yml
kubectl delete -f kindling-prometheus-service.yml
kubectl delete -f kindling-prometheus-rabc.yml

kubectl delete -f kindling-deploy.yml
kubectl delete cm kindlingcfg -n kindling
kubectl delete cm camera-front-config -n kindling
kubectl delete -f kindling-clusterrolebinding.yml
kubectl delete -f kindling-clusterrole.yml
kubectl delete serviceaccount kindling-agent -nkindling
