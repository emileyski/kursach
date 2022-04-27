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
    GameObject player;
    public string whoIsIt;
    protected Animator animator;
    [SerializeField] float atackRange;
    protected bool isActivated = false, atacking = false;
    void Start()
    {
        animator = GetComponent<Animator>();
        agent = GetComponent<NavMeshAgent>();
        player = GameObject.Find("Player");
        agent.updateRotation = false;
        agent.updateUpAxis = false;

    }
    public void activation()
    {
        animator.SetTrigger("isActivated");
        isActivated = true;
        GetComponentInChildren<Collider2D>().enabled = false;
    }
    // Update is called once per frame
    void Update()
    {
        if (isActivated)
        {
            if(Vector3.Distance(transform.position, player.transform.position) > atackRange) 
                agent.SetDestination(player.transform.position);
            bool x = (Vector3.Distance(transform.position, player.transform.position) < atackRange) ? true : false;
            if (x && !atacking)
            {
                StartCoroutine("Atack");
            }
            transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
        }
    }
    IEnumerator Atack()
    {
        atacking = true;
        animator.SetBool("IsAttacking", true);
        GetComponentInChildren<Collider2D>().enabled = true;
        yield return new WaitForSeconds(0.5f);
        animator.SetBool("IsAttacking", false);
        GetComponentInChildren<Collider2D>().enabled = false;
        yield return new WaitForSeconds(1.5f);
        atacking = false;
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponentInParent<weaponController>())
        {
            lifeCount -= collision.GetComponentInParent<weaponController>().damageCount;
            if (lifeCount <= 0)
            {
                agent.isStopped = true;
                agent.speed = 0;
                animator.SetTrigger("died");
                isActivated = false;
                transform.Find("Weapon").gameObject.SetActive(false);
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
