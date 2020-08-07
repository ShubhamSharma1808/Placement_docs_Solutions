Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    Node *res, *prev_A=nullptr, *prev_B=nullptr, *end=nullptr;
    head_A->data > head_B->data ? (res=head_B) : (res=head_A) ;
    if(res==head_A){
        end = head_A;
        prev_A = head_A;
        head_A=head_A->next;
    }
    else{
        end = head_B;
        prev_B = head_B;
        head_B = head_B->next;
    }
    while(head_A != nullptr && head_B != nullptr){
        if(head_A->data <= head_B->data){
            if(end!=prev_A)
                end->next = head_A;
            end = head_A;
            prev_A = head_A;
            head_A = head_A->next;
        }
        else{
            if(end!=prev_B)
                end->next = head_B;
            end = head_B;
            prev_B = head_B;
            head_B = head_B->next;
        }
    }
    if(head_A==nullptr && end!=prev_B)
        end->next = head_B;
    else if(head_B==nullptr && end!=prev_A)
        end->next = head_A;
    return res;
} 
