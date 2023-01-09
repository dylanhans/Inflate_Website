# Inflate Investigate
## Crow
### Building and Running
```
    docker build --pull --rm -f "Dockerfile" -t src:latest "."
    docker run --name crow --rm -d  -p 18080:18080/tcp src:latest
```
