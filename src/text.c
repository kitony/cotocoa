            while ((count_worker != count_requester) && ((count_requester - count_worker) % buffersize == 0) && (count_requester != loop_number - 1))
            {
                MPI_Win_flush(head_requester, win_count_requester);
            }