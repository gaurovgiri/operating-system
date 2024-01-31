#define N 100
semaphore full = 0
sempahore empty = N
semaphore mutex = 1;

void producer(void){
    int item;
    while (TRUE){
        item = produce_item();
        down(&empty);
        down(&mutex);
        insert(item);
        up(&mutex);
        up(&full);
    }
}

void consumer(void){
    int item;
    while(True){
        down(&full);
        down(&mutex);
        remove item;
        up(&mutex);
        up(&empty);
        consume(item);
    }
}


/*--------------Monitor Implementation---------------*/

monitor ProducerConsumer:
    condition full, empty;
    integer count;

    procedure insert(item: integer):
        begin
            if count == N then wait(full);
            insert_item;
            count += 1
            if count == 1 then signal(empty);
        end;
    
    procedure remove: integer:
        begin
            if count == 0 then wait(empty);
            remove_item;
            count -= 1
            if count == N-1 then signal(full);
        end;
    
    count := 0;
end


procedure producer:
    begin
        while true do
        begin
            item = produceItem();
            ProducerConsumer.insert(item);
        end;
    end

procedure consumer:
    begin
        while true do
        begin
            item = ProducerConsumer.remove()
            consume_item(item);
        end
    end
    
