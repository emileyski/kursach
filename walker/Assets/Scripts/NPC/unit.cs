using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class unit : MonoBehaviour
{
    [SerializeField]
    protected int lifeCount;

    private roomParameters currentRoom;

    protected NavMeshAgent agent;
    //до обновлений;
    GameObject player;
    public string whoIsIt;
    protected Animator animator;
    [SerializeField] float atackRange;
    protected bool isActivated = false, atacking = false;
    protected virtual void Start()
    {
        animator = GetComponent<Animator>();
        agent = GetComponent<NavMeshAgent>();
        player = GameObject.Find("Player");
        agent.updateRotation = false;
        agent.updateUpAxis = false;

    }
    public virtual void activation()
    {
        animator.SetTrigger("isActivated");
        isActivated = true;
    }
    // Update is called once per frame
    void Update()
    {
        if (isActivated)
        {
            agent.SetDestination(player.transform.position);
            bool x = (Vector3.Distance(transform.position, player.transform.position) < atackRange) ? true : false;
            if (animator.GetBool("IsAttacking") != x)
                animator.SetBool("IsAttacking", x);
            transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
        }
    }
    IEnumerator Atack()
    {
        yield return new WaitForSeconds(0.5f);
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponentInParent<weaponController>())
        {
            lifeCount -= collision.GetComponentInParent<weaponController>().damageCount;
            if (lifeCount <= 0)
            {
                agent.isStopped = true;
                animator.SetTrigger("isDied");
                isActivated = false;
                transform.Find("Weapon").gameObject.SetActive(false);
                GetComponent<CapsuleCollider2D>().enabled = false;
            }
        }
        if (collision.GetComponentInParent<roomParameters>())
        {
            print("good");
            currentRoom = collision.GetComponentInParent<roomParameters>();
            unit[] x = currentRoom.unitsInRoom;
            currentRoom.unitsInRoom = new unit[currentRoom.unitsInRoom.Length + 1];
            for(int i = 0; i < currentRoom.unitsInRoom.Length - 1; i++)
            {
                currentRoom.unitsInRoom[i] = x[i];
            }
            currentRoom.unitsInRoom[currentRoom.unitsInRoom.Length - 1] = gameObject.GetComponent<unit>();
        }
    }
}
